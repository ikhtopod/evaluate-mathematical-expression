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

    void ABinaryOperator::Interpret(TokenSequence& tokenSequence) {
        if (tokenSequence.GetToken().IsBinaryOperator(tokenSequence.GetPrevToken())) {
            tokenSequence.Shift();
        }

        Token token = tokenSequence.GetToken();

        if (token.IsCorrect()) {
            if (token.IsNumber()) {
                m_second = new Number {};
            } else if (token.IsUnaryOperator(tokenSequence.GetPrevToken())) {
                if (token.IsNegative()) {
                    m_second = new Negative {};
                }
            } else if (token.IsBeginScope()) {
                m_second = new Scope {};
            }
        }

        m_second->Interpret(tokenSequence);
    }


}
