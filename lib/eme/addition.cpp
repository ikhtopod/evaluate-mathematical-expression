#include "addition.h"


namespace reclue {

    EPrecedence Addition::Precedence() const { return EPrecedence::BINARY_ADDITIVE; }
    double Addition::Calculate() const { return m_first->Calculate() + m_second->Calculate(); }

}
