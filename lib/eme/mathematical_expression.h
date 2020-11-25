#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_MATHEMATICAL_EXPRESSION_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_MATHEMATICAL_EXPRESSION_H

#include <string>

#include "token_sequence.h"
#include "scope.h"


namespace reclue {

    class MathematicalExpression final {
    private:
        TokenSequence m_tokenSequence;
        Scope* m_scope;
        double m_result;

    public:
        explicit MathematicalExpression(const std::string_view& sequence);
        ~MathematicalExpression();

        double Evaluate();
    };

}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_MATHEMATICAL_EXPRESSION_H
