#include "number.h"

#include <string>


namespace reclue {

    Number::Number() : Number { 0.0 } {}

    Number::Number(double value) : m_value { value } {}

    Number::Number(SymbolSequence& symbolSequence) :
            Number { Number::ExtractNumber(symbolSequence) } {}

    double Number::ExtractNumber(SymbolSequence& symbolSequence) {
        std::string number {};

        Symbol symbol = symbolSequence.GetSymbol();
        while (symbol.IsNumber()) {
            number.push_back(symbol.GetSymbol());
            symbolSequence.Shift();
            symbol = symbolSequence.GetSymbol();
        }

        return !number.empty() ? std::stod(number) : 0.0;
    }

    EPrecedence Number::Precedence() const { return EPrecedence::EMPTY; }
    double Number::Calculate() const { return m_value; }

}
