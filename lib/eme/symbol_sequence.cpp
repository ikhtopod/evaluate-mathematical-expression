#include "symbol_sequence.h"


namespace reclue {

    bool SymbolSequence::HasNext() const {
        return !m_sequence.empty() && m_position < m_sequence.size();
    }

    bool SymbolSequence::SkipIncorrectSymbols() {
        for (;; ++m_position) {
            if (!HasNext()) {
                m_currentSymbol = Symbol {};
                return false;
            }

            m_currentSymbol = Symbol { m_sequence[m_position] };

            if (m_currentSymbol.IsCorrect()) return true;
        }
    }

    SymbolSequence::SymbolSequence(const std::string_view& expression) :
            m_sequence { expression }, m_position { 0 }, m_prevSymbol {},
            m_currentSymbol { HasNext() ? m_sequence[m_position] : Symbol::DEADEND } {
        SkipIncorrectSymbols();
    }

    Symbol SymbolSequence::GetSymbol() const { return m_currentSymbol; }
    Symbol SymbolSequence::GetPrevSymbol() const { return m_prevSymbol; }

    bool SymbolSequence::IsStartPosition() const { return m_position == 0 && HasNext(); }

    bool SymbolSequence::Shift() {
        if (HasNext()) {
            m_prevSymbol = m_currentSymbol;
            ++m_position;
            return SkipIncorrectSymbols();
        }

        return false;
    }

}
