#include "subtract.h"


namespace reclue {

    Subtract::Subtract(IExpression* first) : ABinaryOperator { first } {}

    double Subtract::Calculate() {
        return m_first->Calculate() - m_second->Calculate();
    }

}
