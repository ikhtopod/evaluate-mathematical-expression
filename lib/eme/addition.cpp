#include "addition.h"


namespace reclue {

    double Addition::Calculate() {
        return m_first->Calculate() + m_second->Calculate();
    }

}
