#include "negative.h"


namespace reclue {

    double Negative::Calculate() const { return -(m_expression->Calculate()); }

}
