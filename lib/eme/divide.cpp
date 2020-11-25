#include "divide.h"


namespace reclue {

    Divide::Divide(IExpression* first) : ABinaryOperator { first } {}

    double Divide::Calculate() {
        return m_first->Calculate() / m_second->Calculate();
    }

}
