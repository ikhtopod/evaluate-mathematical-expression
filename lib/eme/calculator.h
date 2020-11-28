#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H


#include <string>

#include "a_expression.h"


namespace reclue {

    class Calculator final {
    private:
        AExpression* root;
        double m_result;

    public:
        explicit Calculator(const std::string_view& sequence);
        ~Calculator();

        double Result();
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_CALCULATOR_H
