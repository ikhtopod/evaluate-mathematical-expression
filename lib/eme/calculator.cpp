#include "calculator.h"

#include <iostream>
#include <stack>

#include "a_expression.h"
#include "number.h"
#include "scope.h"
#include "negative.h"
#include "multiply.h"
#include "divide.h"
#include "addition.h"
#include "subtract.h"


namespace reclue {

    Calculator::Calculator(const std::string_view& sequence) :
            m_result { 0.0 } {

        std::stack<AExpression*> expressions {};
        AExpression* root { nullptr };

        {
            SymbolSequence symbolSequence { sequence };
            std::stack<AExpression*> operators {};

            bool isPossibleUnary = true;
            Symbol symbol = symbolSequence.GetSymbol();
            bool shifted = false;

            while (!symbol.IsDeadEnd()) {
                AExpression* expression { nullptr };

                if (symbol.IsNumber()) {
                    shifted = true;
                    expression = new Number { symbolSequence };
                } else if (symbol.IsOperator()) {
                    shifted = false;

                    if (symbol.IsUnaryOperator() && isPossibleUnary) {

                        if (symbol.IsNegative()) {
                            expression = new Negative {};
                        }//fi

                    } else if (symbol.IsBinaryOperator()) {

                        if (symbol.IsMultiply()) {
                            expression = new Multiply {};
                        } else if (symbol.IsDivide()) {
                            expression = new Divide {};
                        } else if (symbol.IsAddition()) {
                            expression = new Addition {};
                        } else if (symbol.IsSubtract()) {
                            expression = new Subtract {};
                        }//fi

                    } else if (symbol.IsBeginScope()) {
                        expression = new Scope {};
                    }//fi

                }//fi


                if (expression) {
                    while (!operators.empty() && *expression < *operators.top()) {
                        expressions.push(operators.top());
                        operators.pop();
                    }
                    operators.push(expression);
                } else {
                    // Если expression == nullptr, то скорее всего это закрывающая скобка, поэтому
                    // нужно вытолкнуть все из operators в expressions до первой попавшейся скобки
                    while (!operators.empty() && !expression) {
                        expression = dynamic_cast<Scope*>(operators.top());

                        if (!expression) {
                            expressions.push(operators.top());
                            operators.pop();
                        }
                    }

                    delete expression;
                }

                isPossibleUnary = !isPossibleUnary && (symbol.IsBinaryOperator() || symbol.IsBeginScope());

                if (!shifted) symbolSequence.Shift();
                symbol = symbolSequence.GetSymbol();
            }//elihw

            while (!operators.empty()) {
                expressions.push(operators.top());
                operators.pop();
            }//elihw
        }//scope filed expressions


        if (root) m_result = root->Calculate();

        delete root;
    }

    double Calculator::Result() { return m_result; }

} // namespace reclue
