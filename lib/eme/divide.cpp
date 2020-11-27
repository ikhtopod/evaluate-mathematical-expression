#include "divide.h"

#include <limits>


namespace reclue {

    double Divide::Calculate() {
        double first { m_first->Calculate() };
        double second { m_second->Calculate() };
        return second > std::numeric_limits<double>::min() ? first / second : 0.0;
    }

}
