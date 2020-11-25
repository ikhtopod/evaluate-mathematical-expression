#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_DIVIDE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_DIVIDE_H

#include "a_binary_operator.h"


namespace reclue {

    struct Divide : public ABinaryOperator {
        explicit Divide(IExpression* first);
        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_DIVIDE_H
