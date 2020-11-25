#include "number.h"


namespace reclue {

    void Number::Interpret(TokenSequence& tokenSequence) {
        std::string number {};

        for (Token token = tokenSequence.GetToken();
             (token = tokenSequence.GetToken()).IsNumber();
             tokenSequence.Shift()) {

            number.push_back(token.GetSymbol());
        }

        if (!number.empty()) {
            m_value = std::stod(number);
        }
    }

    double Number::Calculate() { return m_value; }

}
