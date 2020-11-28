#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H

#include "a_operator.h"


namespace reclue {

    class AUnaryOperator : public AOperator {
    protected:
        AExpression* m_expression;

    public:
        AUnaryOperator();
        ~AUnaryOperator() override;

        EPrecedence Precedence() const override;

        void SetExpression(AExpression* expression) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H
