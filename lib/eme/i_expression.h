#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_I_EXPRESSION_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_I_EXPRESSION_H

#include "symbol_sequence.h"


namespace reclue {

    class IExpression {
    public:
        virtual ~IExpression() = default;

        virtual void Interpret(SymbolSequence&) = 0;
        virtual double Calculate() = 0;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_I_EXPRESSION_H
