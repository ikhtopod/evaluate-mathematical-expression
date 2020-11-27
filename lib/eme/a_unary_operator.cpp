#include "a_unary_operator.h"

#include "empty.h"
#include "number.h"
#include "negative.h"
#include "scope.h"


namespace reclue {

    AUnaryOperator::AUnaryOperator(AExpression* ancestor) :
            AOperator { ancestor }, m_expression {} {}

    AUnaryOperator::~AUnaryOperator() { delete m_expression; }

    void AUnaryOperator::Interpret(SymbolSequence& symbolSequence) {
        if (symbolSequence.GetSymbol().IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
            symbolSequence.Shift();
        }

        Symbol symbol = symbolSequence.GetSymbol();

        if (!symbol.IsDeadEnd()) {
            if (symbol.IsNumber()) {
                m_expression = new Number { this };
            } else if (symbol.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (symbol.IsNegative()) {
                    m_expression = new Negative { this };
                }
            } else if (symbol.IsBeginScope()) {
                m_expression = new Scope { this };
            }
        }

        if (m_expression) {
            m_expression->Interpret(symbolSequence);
        } else {
            m_expression = new Empty { this };
        }

        if (symbol.IsEndScope()) {
            symbolSequence.Shift();
        }
    }

}
