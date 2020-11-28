#include "a_binary_operator.h"


namespace reclue {

    ABinaryOperator::ABinaryOperator() : m_first {}, m_second {} {}

    ABinaryOperator::~ABinaryOperator() {
        delete m_second;
        delete m_first;
    }

    void ABinaryOperator::SetExpression(AExpression* first, AExpression* second) {
        m_first = first;
        m_second = second;
    }

}
