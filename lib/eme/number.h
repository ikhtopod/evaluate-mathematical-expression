#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_NUMBER_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_NUMBER_H

#include "a_expression.h"
#include "symbol_sequence.h"


namespace reclue {

    class Number : public AExpression {
    private:
        double m_value;

    private:
        static double ExtractNumber(SymbolSequence& symbolSequence);

    public:
        Number();
        explicit Number(double value);
        explicit Number(SymbolSequence& symbolSequence);

        EPrecedence Precedence() const override;
        double Calculate() const override;
    };

}

#endif //EVALUATE_MATHEMATICAL_EXPRESSION_NUMBER_H
