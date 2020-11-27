#include "a_binary_operator.h"

#include "number.h"
#include "negative.h"
#include "scope.h"


namespace reclue {

    ABinaryOperator::ABinaryOperator(IExpression* first) : m_first { first }, m_second {} {}

    ABinaryOperator::~ABinaryOperator() {
        delete m_second;
        delete m_first;
    }

    void ABinaryOperator::Interpret(SymbolSequence& symbolSequence) {
        if (symbolSequence.GetSymbol().IsBinaryOperator(symbolSequence.GetPrevSymbol())) {
            symbolSequence.Shift();
        }

        Symbol token = symbolSequence.GetSymbol();

        if (token.IsCorrect()) {
            if (token.IsNumber()) {
                m_second = new Number {};
            } else if (token.IsUnaryOperator(symbolSequence.GetPrevSymbol())) {
                if (token.IsNegative()) {
                    m_second = new Negative {};
                }
            } else if (token.IsBeginScope()) {
                m_second = new Scope {};
            }
        }

        m_second->Interpret(symbolSequence);
    }


}
