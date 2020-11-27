#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H

#include "a_operator.h"
#include "symbol_sequence.h"


namespace reclue {

    class AUnaryOperator : public AOperator {
    protected:
        AExpression* m_expression;

    public:
        using AOperator::AOperator;

        explicit AUnaryOperator(AExpression* ancestor);
        ~AUnaryOperator();

        void Interpret(SymbolSequence& symbolSequence) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_UNARY_OPERATOR_H
