#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_ADDITION_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_ADDITION_H

#include "a_binary_operator.h"


namespace reclue {

    struct Addition : public ABinaryOperator {
        explicit Addition(IExpression* first);
        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_ADDITION_H
