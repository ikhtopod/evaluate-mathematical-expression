#include "calculator.h"

#include <iostream>

#include "number.h"
#include "scope.h"
#include "negative.h"
#include "multiply.h"
#include "divide.h"
#include "addition.h"
#include "subtract.h"


namespace reclue {

    Calculator::Calculator(const std::string_view& sequence) :
            m_expressions {}, m_operators {},
            m_symbolSequence { sequence },
            m_result { 0.0 } {

        bool isPossibleUnary = true;
        Symbol symbol = m_symbolSequence.GetSymbol();

        while (!symbol.IsDeadEnd()) {
            if (symbol.IsNumber()) {
                m_expressions.push(new Number { m_symbolSequence });
            } else {
                if (symbol.IsBeginScope()) {
                    m_operators.push(new Scope {});
                } else if (symbol.IsEndScope()) {

                    while (!dynamic_cast<Scope*>(m_operators.top())) {
                        Push();
                    }

                    if (!m_operators.empty()) {
                        m_operators.pop();
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
                        }//fi
                    }//fi

                    if (expression) {
                        while (!m_operators.empty() && *m_operators.top() >= *expression) {
                            Push();
                        }

                        m_operators.push(expression);
                    }
                }//fi

                m_symbolSequence.Shift();
            }

            isPossibleUnary = symbol.IsBinaryOperator() || symbol.IsUnaryOperator() || symbol.IsBeginScope();

            symbol = m_symbolSequence.GetSymbol();
        }//elihw

        while (!m_operators.empty()) {
            Push();
        }//elihw


        if (!m_expressions.empty()) {
            m_result = m_expressions.top()->Calculate();
        }

    }
    void Calculator::Push() {
        if (auto* unary = dynamic_cast<AUnaryOperator*>(m_operators.top())) {
            m_operators.pop();

            AExpression* expression { m_expressions.top() };
            m_expressions.pop();

            unary->SetExpression(expression);
            m_expressions.push(unary);
        } else if (auto* binary = dynamic_cast<ABinaryOperator*>(m_operators.top())) {
            m_operators.pop();

            AExpression* second { m_expressions.top() };
            m_expressions.pop();

            AExpression* first { m_expressions.top() };
            m_expressions.pop();

            binary->SetExpression(first, second);
            m_expressions.push(binary);
        }
    }

    double Calculator::Result() { return m_result; }

} // namespace reclue
