#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H

#include "a_operator.h"
#include "token_sequence.h"


namespace reclue {

    class AUnaryOperator : public AOperator {
    protected:
        IExpression* m_expression;

    public:
        AUnaryOperator();
        ~AUnaryOperator() override;

        void Interpret(TokenSequence& tokenSequence) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H
