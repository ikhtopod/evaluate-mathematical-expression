#include "token_sequence.h"


namespace reclue {

    bool TokenSequence::HasNext() const { return m_position < m_sequence.size(); }

    bool TokenSequence::SkipIncorrectSymbols() {
        for (;; ++m_position) {
            if (!HasNext()) {
                m_currentToken = Token {};
                return false;
            }

            m_currentToken = Token { m_sequence[m_position] };

            if (m_currentToken.IsCorrect()) return true;
        }
    }

    TokenSequence::TokenSequence(const std::string_view& expression) :
            m_sequence { expression }, m_position { 0 }, m_prevToken {},
            m_currentToken { HasNext() ? m_sequence[m_position] : '\0' } {
        SkipIncorrectSymbols();
    }

    Token TokenSequence::GetToken() const { return m_currentToken; }
    Token TokenSequence::GetPrevToken() const { return m_prevToken; }

    bool TokenSequence::Shift() {
        if (HasNext()) {
            m_prevToken = m_currentToken;
            ++m_position;
            return SkipIncorrectSymbols();
        }

        return false;
    }

}
