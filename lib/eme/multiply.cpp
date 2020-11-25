#include "multiply.h"


namespace reclue {

    Multiply::Multiply(IExpression* first) : ABinaryOperator { first } {}

    double Multiply::Calculate() {
        return m_first->Calculate() * m_second->Calculate();
    }

}
