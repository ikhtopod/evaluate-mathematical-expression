#include "a_unary_operator.h"

#include "empty.h"
#include "number.h"
#include "negative.h"
#include "scope.h"


namespace reclue {

    AUnaryOperator::AUnaryOperator() : m_expression {} {}
    AUnaryOperator::~AUnaryOperator() { delete m_expression; }

    void AUnaryOperator::Interpret(SymbolSequence& symbolSequence) {
        if (symbolSequence.GetSymbol().IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
            symbolSequence.Shift();
        }

        Symbol token = symbolSequence.GetSymbol();

        if (token.IsCorrect()) {
            if (token.IsNumber()) {
                m_expression = new Number {};
            } else if (token.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (token.IsNegative()) {
                    m_expression = new Negative {};
                }
            } else if (token.IsBeginScope()) {
                m_expression = new Scope {};
            }
        }

        if (!m_expression) {
            m_expression = new Empty {};
        }

        m_expression->Interpret(symbolSequence);
    }

}
