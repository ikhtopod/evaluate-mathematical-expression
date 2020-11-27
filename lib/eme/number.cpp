#include "number.h"


namespace reclue {

    void Number::Interpret(SymbolSequence& symbolSequence) {
        std::string number {};

        for (Symbol symbol = symbolSequence.GetSymbol();
             (symbol = symbolSequence.GetSymbol()).IsNumber();
             symbolSequence.Shift()) {

            number.push_back(symbol.GetSymbol());
        }

        if (!number.empty()) {
            m_value = std::stod(number);
        }
    }

    double Number::Calculate() { return m_value; }

}
