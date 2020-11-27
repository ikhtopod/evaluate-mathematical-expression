#include "number.h"


namespace reclue {

    void Number::Interpret(SymbolSequence& symbolSequence) {
        std::string number {};

        for (Symbol token = symbolSequence.GetSymbol();
             (token = symbolSequence.GetSymbol()).IsNumber();
             symbolSequence.Shift()) {

            number.push_back(token.GetSymbol());
        }

        if (!number.empty()) {
            m_value = std::stod(number);
        }
    }

    double Number::Calculate() { return m_value; }

}
