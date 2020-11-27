#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_NUMBER_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_NUMBER_H

#include "i_expression.h"
#include "symbol_sequence.h"


namespace reclue {

    class Number : public IExpression {
    private:
        double m_value {};

    public:
        void Interpret(SymbolSequence& symbolSequence) override;
        double Calculate() override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_NUMBER_H
