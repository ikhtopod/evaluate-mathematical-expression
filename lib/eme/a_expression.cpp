#include "a_expression.h"


namespace reclue {

    bool AExpression::HasNoPrecedence() const {
        return this->Precedence() == EPrecedence::EMPTY;
    }

    bool AExpression::IsUnaryPrecedence() const {
        return this->Precedence() == EPrecedence::UNARY;
    }

    bool AExpression::operator>=(const AExpression& rhs) const {
        if (rhs.HasNoPrecedence() || this->HasNoPrecedence() ||
            (rhs.IsUnaryPrecedence() && this->IsUnaryPrecedence())) {
            return false;
        }

        return rhs.Precedence() >= this->Precedence();
    }

}
