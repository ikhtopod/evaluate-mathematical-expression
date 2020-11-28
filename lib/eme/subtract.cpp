#include "subtract.h"


namespace reclue {

    EPrecedence Subtract::Precedence() const { return EPrecedence::BINARY_ADDITIVE; }
    double Subtract::Calculate() const { return m_first->Calculate() - m_second->Calculate(); }

}
