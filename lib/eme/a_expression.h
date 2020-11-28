#ifndef EVALUATE_MATHEMATICAL_EXPRESSION_A_EXPRESSION_H
#define EVALUATE_MATHEMATICAL_EXPRESSION_A_EXPRESSION_H

#include <cstdint>
#include <memory>

#include "symbol_sequence.h"


namespace reclue {

    enum class EPrecedence : uint8_t {
        SCOPE,
        NUMBER,
        UNARY,
        BINARY_MULTIPLICATIVE,
        BINARY_ADDITIVE,
    };

    struct AExpression {
        virtual ~AExpression() = default;

        virtual EPrecedence Precedence() const = 0;
        virtual double Calculate() const = 0;

        virtual bool operator<(const AExpression& rhs) const;
    };


}


#endif //EVALUATE_MATHEMATICAL_EXPRESSION_A_EXPRESSION_H
