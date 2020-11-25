#include "addition.h"


namespace reclue {

    Addition::Addition(IExpression* first) : ABinaryOperator { first } {}

    double Addition::Calculate() {
        return m_first->Calculate() + m_second->Calculate();
    }

}
