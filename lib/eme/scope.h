#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H

#include "a_operator.h"


namespace reclue {

    struct Scope final : public AExpression {
        EPrecedence Precedence() const override;
        double Calculate() const override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_SCOPE_H
