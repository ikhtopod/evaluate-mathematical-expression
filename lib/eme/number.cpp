#include "number.h"

#include <string>


namespace reclue {

    void Number::Interpret(SymbolSequence& symbolSequence) {
        std::string number {};

        Symbol symbol = symbolSequence.GetSymbol();
        while (symbol.IsNumber()) {
            number.push_back(symbol.GetSymbol());
            symbolSequence.Shift();
            symbol = symbolSequence.GetSymbol();
        }

        if (!number.empty()) {
            m_value = std::stod(number);
        }
    }

    double Number::Calculate() { return m_value; }

}
