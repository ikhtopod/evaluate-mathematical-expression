#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_TOKEN_SEQUENCE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_TOKEN_SEQUENCE_H

#include <string>

#include "token.h"


namespace reclue {

    class TokenSequence {
    private:
        const std::string_view& m_sequence;
        size_t m_position;
        Token m_prevToken;
        Token m_currentToken;

    private:
        bool HasNext() const;
        bool SkipIncorrectSymbols();

    public:
        explicit TokenSequence(const std::string_view& expression);

        Token GetToken() const;
        Token GetPrevToken() const;

        bool Shift();

    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_TOKEN_SEQUENCE_H
