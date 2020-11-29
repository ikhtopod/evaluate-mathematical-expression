#include "calculator.h"

#include <stack>

#include "symbol_sequence.h"
#include "number.h"
#include "scope.h"
#include "a_unary_operator.h"
#include "negative.h"
#include "a_binary_operator.h"
#include "multiply.h"
#include "divide.h"
#include "addition.h"
#include "subtract.h"


namespace reclue {

    using StackExpressions = std::stack<AExpression*>;


    void PushUnary(AUnaryOperator* unary, StackExpressions& expressions) {
        AExpression* expression { expressions.top() };
        expressions.pop();

        unary->SetExpression(expression);
        expressions.push(unary);
    }

    void PushBinary(ABinaryOperator* binary, StackExpressions& expressions) {
        AExpression* second { expressions.top() };
        expressions.pop();

        AExpression* first { expressions.top() };
        expressions.pop();

        binary->SetExpression(first, second);
        expressions.push(binary);
    }

    void PushOperator(StackExpressions& operators, StackExpressions& expressions) {
        AExpression* expression { operators.top() };
        operators.pop();

        if (auto* unary = dynamic_cast<AUnaryOperator*>(expression)) {
            PushUnary(unary, expressions);
        } else if (auto* binary = dynamic_cast<ABinaryOperator*>(expression)) {
            PushBinary(binary, expressions);
        }
    }

    AExpression* PolishPotationTree(const std::string_view& sequence) {
        SymbolSequence symbolSequence { sequence };
        StackExpressions expressions {};
        StackExpressions operators {};

        bool isPossibleUnary = true;
        Symbol symbol = symbolSequence.GetSymbol();

        while (!symbol.IsDeadEnd()) {
            if (symbol.IsNumber()) {
                expressions.push(new Number { symbolSequence });
            } else {
                if (symbol.IsBeginScope()) {
                    operators.push(new Scope {});
                } else if (symbol.IsEndScope()) {
                    while (!dynamic_cast<Scope*>(operators.top())) {
                        PushOperator(operators, expressions);
                    }

                    if (!operators.empty()) {
                        AExpression* scope = operators.top();
                        operators.pop();
                        delete scope;
                    }
                } else if (symbol.IsOperator()) {
                    AExpression* expression { nullptr };

                    if (symbol.IsUnaryOperator() && isPossibleUnary) {
                        if (symbol.IsNegative()) {
                            expression = new Negative {};
                        }
                    } else if (symbol.IsBinaryOperator()) {
                        if (symbol.IsMultiply()) {
                            expression = new Multiply {};
                        } else if (symbol.IsDivide()) {
                            expression = new Divide {};
                        } else if (symbol.IsAddition()) {
                            expression = new Addition {};
                        } else if (symbol.IsSubtract()) {
                            expression = new Subtract {};
                        }
                    }

                    if (expression) {
                        while (!operators.empty() && *operators.top() >= *expression) {
                            PushOperator(operators, expressions);
                        }

                        operators.push(expression);
                    }
                }

                symbolSequence.Shift();
            }

            isPossibleUnary = symbol.IsBinaryOperator() || symbol.IsUnaryOperator() || symbol.IsBeginScope();

            symbol = symbolSequence.GetSymbol();
        }

        while (!operators.empty()) {
            PushOperator(operators, expressions);
        }

        return expressions.empty() ? new Number {} : expressions.top();
    }


    Calculator::Calculator(const std::string_view& sequence) :
            root { PolishPotationTree(sequence) },
            m_result { root->Calculate() } {}

    Calculator::~Calculator() { delete root; }

    double Calculator::Result() { return m_result; }


} // namespace reclue
