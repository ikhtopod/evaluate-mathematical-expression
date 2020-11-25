#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H

#include "token_sequence.h"
#include "a_operator.h"


namespace reclue {

    class Scope : public AOperator {
    private:
        IExpression* m_expression;

    public:
        Scope();
        ~Scope() override;

        void Interpret(TokenSequence& tokenSequence) override;
        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H
