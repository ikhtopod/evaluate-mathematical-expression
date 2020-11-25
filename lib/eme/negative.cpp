#include "negative.h"


namespace reclue {

    double Negative::Calculate() {
        return -(m_expression->Calculate());
    }

}
