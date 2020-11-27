#include "a_binary_operator.h"

#include "empty.h"
#include "number.h"
#include "negative.h"
#include "scope.h"


namespace reclue {

    ABinaryOperator::ABinaryOperator() : m_first {}, m_second {} {}

    ABinaryOperator::~ABinaryOperator() {
        delete m_second;
        delete m_first;
    }

    void ABinaryOperator::SetFirst(IExpression* first) {
        m_first = first ? first : new Empty {};
    }

    void ABinaryOperator::Interpret(SymbolSequence& symbolSequence) {
        Symbol symbol = symbolSequence.GetSymbol();

        if (symbol.IsBinaryOperator(symbolSequence.GetPrevSymbol())) {
            symbolSequence.Shift();
            symbol = symbolSequence.GetSymbol();
        }

        if (!symbol.IsDeadEnd()) {
            if (symbol.IsNumber()) {
                m_second = new Number {};
            } else if (symbol.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (symbol.IsNegative()) {
                    m_second = new Negative {};
                }
            } else if (symbol.IsBeginScope()) {
                m_second = new Scope {};
            }
        }

        if (m_second) {
            m_second->Interpret(symbolSequence);
            symbolSequence.Shift();
        } else {
            m_second = new Empty {};
        }
    }

}
