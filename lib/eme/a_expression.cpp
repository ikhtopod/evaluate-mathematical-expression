#include "a_expression.h"


namespace reclue {

    bool AExpression::operator<(const AExpression& rhs) const {
        return rhs.Precedence() < this->Precedence();
    }

}
