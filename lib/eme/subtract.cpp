#include "subtract.h"


namespace reclue {

    double Subtract::Calculate() {
        return m_first->Calculate() - m_second->Calculate();
    }

}
