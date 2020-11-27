#include "symbol.h"

#include <cctype>


namespace reclue {

    Symbol::Symbol(char symbol) : m_symbol { symbol } {}

    Symbol::Symbol() : Symbol { Symbol::DEADEND } {}
    Symbol::Symbol(const Symbol& symbol) : m_symbol { symbol.m_symbol } {}
    Symbol::Symbol(Symbol&& symbol) noexcept: m_symbol { symbol.m_symbol } {}

    Symbol& Symbol::operator=(const Symbol& symbol) {
        if (this != &symbol)
            this->m_symbol = symbol.m_symbol;
        return *this;
    }

    Symbol& Symbol::operator=(Symbol&& symbol) noexcept {
        if (this != &symbol)
            this->m_symbol = symbol.m_symbol;
        return *this;
    }

    Symbol::~Symbol() = default;

    char Symbol::GetSymbol() const { return m_symbol; }

    /* Symbol info */
    bool Symbol::IsDeadEnd() const { return m_symbol == Symbol::DEADEND; }

    bool Symbol::IsDigit() const { return std::isdigit(m_symbol); }
    bool Symbol::IsNumberSeparator() const { return m_symbol == '.'; }

    bool Symbol::IsNumber() const { return IsDigit() || IsNumberSeparator(); }
    bool Symbol::IsBeginScope() const { return m_symbol == '('; }
    bool Symbol::IsEndScope() const { return m_symbol == ')'; }

    bool Symbol::IsSubtract() const { return m_symbol == '-'; }
    bool Symbol::IsAddition() const { return m_symbol == '+'; }
    bool Symbol::IsDivide() const { return m_symbol == '/'; }
    bool Symbol::IsMultiply() const { return m_symbol == '*'; }

    bool Symbol::IsNegative() const { return m_symbol == '-'; }

    bool Symbol::IsOperator() const {
        return IsSubtract() || IsAddition() || IsDivide() || IsMultiply();
    }

    bool Symbol::IsUnaryOperator(const Symbol& prev) const {
        if (IsNegative()) {
            return prev.IsOperator() || prev.IsBeginScope() || !prev.IsCorrect();
        }

        return false;
    }

    bool Symbol::IsBinaryOperator(const Symbol& prev) const {
        return IsOperator() && !IsUnaryOperator(prev);
    }

    bool Symbol::IsCorrect() const {
        switch (m_symbol) {
            case ' ':
            case Symbol::DEADEND:
                return false;
            default:
                return true;
        }
    }

}
