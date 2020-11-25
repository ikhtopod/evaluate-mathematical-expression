#include "token.h"

#include <cctype>


namespace reclue {

    Token::Token(char symbol) : m_symbol { symbol } {}

    Token::Token() : Token { '\0' } {}
    Token::Token(const Token& token) : m_symbol { token.m_symbol } {}
    Token::Token(Token&& token) noexcept: m_symbol { token.m_symbol } {}

    Token& Token::operator=(const Token& token) {
        if (this != &token)
            this->m_symbol = token.m_symbol;
        return *this;
    }

    Token& Token::operator=(Token&& token) noexcept {
        if (this != &token)
            this->m_symbol = token.m_symbol;
        return *this;
    }

    Token::~Token() = default;

    char Token::GetSymbol() const { return m_symbol; }

    /* Token info */
    bool Token::IsDigit() const { return std::isdigit(m_symbol); }
    bool Token::IsNumberSeparator() const { return m_symbol == '.'; }
    bool Token::IsNumber() const { return IsDigit() || IsNumberSeparator(); }

    bool Token::IsBeginScope() const { return m_symbol == '('; }
    bool Token::IsEndScope() const { return m_symbol == ')'; }

    bool Token::IsSubtract() const { return m_symbol == '-'; }
    bool Token::IsAddition() const { return m_symbol == '+'; }
    bool Token::IsDivide() const { return m_symbol == '/'; }
    bool Token::IsMultiply() const { return m_symbol == '*'; }

    bool Token::IsNegative() const { return m_symbol == '-'; }

    bool Token::IsOperator() const {
        return IsSubtract() || IsAddition() || IsDivide() || IsMultiply();
    }

    bool Token::IsUnaryOperator(const Token& prev) const {
        if (IsNegative()) {
            return prev.IsOperator() || prev.IsBeginScope() || !prev.IsCorrect();
        }

        return false;
    }

    bool Token::IsBinaryOperator(const Token& prev) const {
        return IsOperator() && !IsUnaryOperator(prev);
    }

    bool Token::IsCorrect() const {
        switch (m_symbol) {
            case ' ':
            case '\0':
                return false;
            default:
                return true;
        }
    }

}
