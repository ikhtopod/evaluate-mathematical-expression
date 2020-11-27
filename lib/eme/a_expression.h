#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_EXPRESSION_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_EXPRESSION_H

#include "symbol_sequence.h"


namespace reclue {

    class AExpression {
    public:
        AExpression* m_ancestor;

    public:
        explicit AExpression(AExpression* ancestor);
        virtual ~AExpression() = default;

        bool HasAncestor() const;

    public:
        virtual void Interpret(SymbolSequence&) = 0;
        virtual double Calculate() = 0;
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_EXPRESSION_H
