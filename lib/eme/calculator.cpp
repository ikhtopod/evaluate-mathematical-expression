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
            AExpression* expression { nullptr };

            if (symbol.IsNumber()) {
                expression = new Number { m_symbolSequence };
            } else if (symbol.IsOperator()) {

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
                PushOperator(expression);
            } else {
                while (!m_operators.empty() && !expression) {
                    if (m_operators.top()->Precedence() == EPrecedence::SCOPE) {
                        expression = m_operators.top();
                        m_operators.pop();
                    } else {
                        PushExpression();
                    }//fi
                }//elihw

                delete expression;
                expression = nullptr;
            }//fi


            isPossibleUnary = !isPossibleUnary && (symbol.IsBinaryOperator() || symbol.IsBeginScope());
            //isPossibleUnary = symbol.IsBinaryOperator() || symbol.IsBeginScope();

            if (expression && (expression->Precedence() != EPrecedence::NUMBER)) {
                m_symbolSequence.Shift();
            }//fi

            symbol = m_symbolSequence.GetSymbol();
        }//elihw

        while (!m_operators.empty()) {
            PushExpression();
        }//elihw


        if (!m_expressions.empty()) {
            m_result = m_expressions.top()->Calculate();
        }
    }

    void Calculator::PushOperator(AExpression* expression) {
        if (!expression) return;

        while (!m_operators.empty() && (*expression < *m_operators.top())) {
            PushExpression();
        }

        m_operators.push(expression);
    }

    void Calculator::PushExpression() {
        if (m_operators.empty()) return;

        AExpression* expression { m_operators.top() };
        m_operators.pop();

        if (auto* unary = dynamic_cast<AUnaryOperator*>(expression)) {
            AExpression* first = m_expressions.top();
            m_expressions.pop();
            unary->SetExpression(first);
        } else if (auto* binary = dynamic_cast<ABinaryOperator*>(expression)) {
            AExpression* second = m_expressions.top();
            m_expressions.pop();
            AExpression* first = m_expressions.top();
            m_expressions.pop();
            binary->SetExpression(first, second);
        }

        m_expressions.push(expression);
    }

    double Calculator::Result() { return m_result; }

} // namespace reclue
