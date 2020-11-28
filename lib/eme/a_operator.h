#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_OPERATOR_H

#include "a_expression.h"


namespace reclue {

    struct AOperator : public AExpression {
        virtual void SetExpression(AExpression* expression);
        virtual void SetExpression(AExpression* first, AExpression* second);
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_OPERATOR_H
