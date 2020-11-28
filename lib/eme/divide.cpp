#include "divide.h"

#include <limits>


namespace reclue {

    EPrecedence Divide::Precedence() const { return EPrecedence::BINARY_MULTIPLICATIVE; }

    double Divide::Calculate() const {
        double first { m_first->Calculate() };
        double second { m_second->Calculate() };
        return second > std::numeric_limits<double>::min() ? first / second : 0.0;
    }

}
