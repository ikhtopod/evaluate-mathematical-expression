#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H

#include "a_operator.h"


namespace reclue {

    class Scope final : public AOperator {
    private:
        AExpression* m_expression;

    public:
        Scope();
        ~Scope() override;

        EPrecedence Precedence() const override;
        double Calculate() const override;

        void SetExpression(AExpression* expression) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H
