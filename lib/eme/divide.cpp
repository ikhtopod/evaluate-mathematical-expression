#include "divide.h"


namespace reclue {

    double Divide::Calculate() {
        return m_first->Calculate() / m_second->Calculate();
    }

}
