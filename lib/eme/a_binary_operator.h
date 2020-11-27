#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H

#include "a_operator.h"
#include "symbol_sequence.h"


namespace reclue {

    class ABinaryOperator : public AOperator {
    protected:
        AExpression* m_first;
        AExpression* m_second;

    public:
        using AOperator::AOperator;

        explicit ABinaryOperator(AExpression* ancestor);
        ~ABinaryOperator();

        void SetFirst(AExpression* first);
        void Interpret(SymbolSequence& symbolSequence) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H
