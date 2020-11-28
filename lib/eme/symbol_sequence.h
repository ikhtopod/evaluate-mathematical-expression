#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_SYMBOL_SEQUENCE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_SYMBOL_SEQUENCE_H

#include <string>

#include "symbol.h"


namespace reclue {

    class SymbolSequence {
    private:
        const std::string_view& m_sequence;
        size_t m_position;
        Symbol m_currentSymbol;

    private:
        bool HasNext() const;
        bool SkipIncorrectSymbols();

    public:
        explicit SymbolSequence(const std::string_view& expression);

        Symbol GetSymbol() const;
        bool IsStartPosition() const;

        bool Shift();

    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_SYMBOL_SEQUENCE_H
