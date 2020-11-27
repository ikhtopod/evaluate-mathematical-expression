#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_SUBTRACT_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_SUBTRACT_H

#include "a_binary_operator.h"


namespace reclue {

    struct Subtract : public ABinaryOperator {
        using ABinaryOperator::ABinaryOperator;

        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_SUBTRACT_H
