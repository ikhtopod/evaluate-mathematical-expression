#include "multiply.h"


namespace reclue {

    EPrecedence Multiply::Precedence() const { return EPrecedence::BINARY_MULTIPLICATIVE; }
    double Multiply::Calculate() const { return m_first->Calculate() * m_second->Calculate(); }

}
