#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H

#include <string>

#include "symbol_sequence.h"


namespace reclue {

    class Calculator final {
    private:
        double m_result;

    public:
        explicit Calculator(const std::string_view& sequence);

        double Result();
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H
