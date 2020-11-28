#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H

#include <stack>
#include <string>

#include "symbol_sequence.h"
#include "a_expression.h"


namespace reclue {

    class Calculator final {
        using StackExpressions = std::stack<AExpression*>;

    private:
        StackExpressions m_expressions;
        StackExpressions m_operators;
        SymbolSequence m_symbolSequence;

        double m_result;

    private:
        void PushExpression();
        void PushOperator(AExpression* expression);

    public:
        explicit Calculator(const std::string_view& sequence);

        double Result();
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H
