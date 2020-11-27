#include "a_unary_operator.h"

#include "empty.h"
#include "number.h"
#include "negative.h"
#include "scope.h"


namespace reclue {

    AUnaryOperator::AUnaryOperator() : m_expression {} {}
    AUnaryOperator::~AUnaryOperator() { delete m_expression; }

    void AUnaryOperator::Interpret(SymbolSequence& symbolSequence) {
        Symbol symbol = symbolSequence.GetSymbol();

        if (symbol.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
            symbolSequence.Shift();
            symbol = symbolSequence.GetSymbol();
        }

        if (!symbol.IsDeadEnd()) {
            if (symbol.IsNumber()) {
                m_expression = new Number {};
            } else if (symbol.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (symbol.IsNegative()) {
                    m_expression = new Negative {};
                }
            } else if (symbol.IsBeginScope()) {
                m_expression = new Scope {};
            }
        }

        if (m_expression) {
            m_expression->Interpret(symbolSequence);
            symbolSequence.Shift();
        } else {
            m_expression = new Empty {};
        }
    }

}
