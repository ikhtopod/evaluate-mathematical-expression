#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H

#include "i_expression.h"
#include "symbol_sequence.h"


namespace reclue {

    struct Empty : public IExpression {
        void Interpret(SymbolSequence&) override;
        double Calculate() override;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_EMPTY_H
