#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H

#include "i_expression.h"
#include "token_sequence.h"


namespace reclue {

    struct Empty : public IExpression {
        void Interpret(TokenSequence&) override;
        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H
