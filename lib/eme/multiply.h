#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_MULTIPLY_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_MULTIPLY_H

#include "a_binary_operator.h"


namespace reclue {

    struct Multiply : public ABinaryOperator {
        EPrecedence Precedence() const override;
        double Calculate() const override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_MULTIPLY_H
