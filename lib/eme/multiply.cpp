#include "multiply.h"


namespace reclue {

    double Multiply::Calculate() {
        return m_first->Calculate() * m_second->Calculate();
    }

}
