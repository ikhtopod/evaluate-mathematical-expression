#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_CALC_HPP
#define EVALUATE_MATHEMATICAL_EXPRESSION_CALC_HPP

#include "eme/calculator.h"


namespace reclue {

    double calc(const std::string& expression) {
        return Calculator(expression).Result();
    }

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_CALC_HPP
