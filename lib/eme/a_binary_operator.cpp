#include "a_binary_operator.h"

#include "empty.h"
#include "number.h"
#include "negative.h"
#include "scope.h"


namespace reclue {

    ABinaryOperator::ABinaryOperator(AExpression* ancestor) :
            AOperator { ancestor }, m_first {}, m_second {} {}

    ABinaryOperator::~ABinaryOperator() {
        delete m_second;
        delete m_first;
    }

    void ABinaryOperator::SetFirst(AExpression* first) {
        m_first = first ? first : new Empty { this };
    }

    void ABinaryOperator::Interpret(SymbolSequence& symbolSequence) {
        m_first = m_ancestor;

        if (m_first) {
            m_ancestor = m_first->m_ancestor->m_ancestor;
        }

        if (symbolSequence.GetSymbol().IsBinaryOperator(symbolSequence.GetPrevSymbol())) {
            symbolSequence.Shift();
        }

        Symbol symbol = symbolSequence.GetSymbol();

        if (!symbol.IsDeadEnd()) {
            if (symbol.IsNumber()) {
                m_second = new Number { this };
            } else if (symbol.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (symbol.IsNegative()) {
                    m_second = new Negative { this };
                }
            } else if (symbol.IsBeginScope()) {
                m_second = new Scope { this };
            }
        }

        if (m_second) {
            m_second->Interpret(symbolSequence);
        } else {
            m_second = new Empty { this };
        }

        if (symbol.IsEndScope()) {
            symbolSequence.Shift();
        }
    }

}
