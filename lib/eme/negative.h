#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_NEGATIVE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_NEGATIVE_H

#include "a_unary_operator.h"


namespace reclue {

    struct Negative : public AUnaryOperator {
        using AUnaryOperator::AUnaryOperator;

        double Calculate() override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_NEGATIVE_H
