#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H

#include "a_operator.h"


namespace reclue {

    class ABinaryOperator : public AOperator {
    protected:
        AExpression* m_first;
        AExpression* m_second;

    public:
        ABinaryOperator();
        ~ABinaryOperator() override;

        void SetExpression(AExpression* first, AExpression* second) override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_BINARY_OPERATOR_H
