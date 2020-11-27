#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H

#include "a_expression.h"
#include "symbol_sequence.h"


namespace reclue {

    struct Empty : public AExpression {
        using AExpression::AExpression;

        void Interpret(SymbolSequence&) override;
        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H
