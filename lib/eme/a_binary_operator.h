#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H

#include "a_operator.h"
#include "symbol_sequence.h"


namespace reclue {

    class ABinaryOperator : public AOperator {
    protected:
        IExpression* m_first;
        IExpression* m_second;

    public:
        explicit ABinaryOperator(IExpression* first);
        ~ABinaryOperator() override;

        void Interpret(SymbolSequence& symbolSequence) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H
