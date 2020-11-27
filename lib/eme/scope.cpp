#include "scope.h"

#include "empty.h"
#include "number.h"
#include "negative.h"
#include "subtract.h"
#include "addition.h"
#include "divide.h"
#include "multiply.h"


namespace reclue {

    Scope::Scope(AExpression* ancestor) : AOperator { ancestor }, m_expression {} {}

    Scope::~Scope() { delete m_expression; }

    void Scope::Interpret(SymbolSequence& symbolSequence) {
        if (symbolSequence.GetSymbol().IsBeginScope() && !symbolSequence.IsStartPosition()) {
            symbolSequence.Shift();
        }

        Symbol symbol = symbolSequence.GetSymbol();

        // AExpression* prevExpression { nullptr };
        while (!symbol.IsDeadEnd()) {
            // prevExpression = m_expression;

            if (symbol.IsNumber()) {
                m_expression = new Number { this };
            } else if (symbol.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (symbol.IsNegative()) {
                    m_expression = new Negative { this };
                }
            } else if (symbol.IsBinaryOperator(symbolSequence.GetPrevSymbol())) {
                ABinaryOperator* binaryOperator { nullptr };

                if (symbol.IsSubtract()) {
                    binaryOperator = new Subtract { this };
                } else if (symbol.IsAddition()) {
                    binaryOperator = new Addition { this };
                } else if (symbol.IsDivide()) {
                    binaryOperator = new Divide { this };
                } else if (symbol.IsMultiply()) {
                    binaryOperator = new Multiply { this };
                }

                if (binaryOperator) {
                    //binaryOperator->SetFirst(prevExpression);
                    m_expression = binaryOperator;
                }
            } else if (symbol.IsBeginScope()) {
                if (symbolSequence.IsStartPosition()) {
                    symbolSequence.Shift();
                }

                m_expression = new Scope { this };
            } else if (symbol.IsEndScope()) {
                if (!m_expression) {
                    m_expression = new Empty { this };
                }
                return;
            }

            if (m_expression) {
                m_expression->Interpret(symbolSequence);
                symbol = symbolSequence.GetSymbol();
            } else {
                m_expression = new Empty { this };
            }

            if (symbol.IsEndScope()) {
                symbolSequence.Shift();
            }
        }

        if (!m_expression) {
            m_expression = new Empty { this };
        }

        if (symbol.IsEndScope()) {
            symbolSequence.Shift();
        }
    }

    double Scope::Calculate() { return m_expression->Calculate(); }

}
