#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_CALC_HPP
#define EVALUATE_MATHEMATICAL_EXPRESSION_CALC_HPP

#include "eme/mathematical_expression.h"


namespace reclue {

    double calc(const std::string& expression) {
        return MathematicalExpression { expression }.Evaluate();
    }

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_CALC_HPP
