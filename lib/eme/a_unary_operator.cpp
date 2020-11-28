#include "a_unary_operator.h"


namespace reclue {

    AUnaryOperator::AUnaryOperator() : m_expression {} {}
    AUnaryOperator::~AUnaryOperator() { delete m_expression; }

    EPrecedence AUnaryOperator::Precedence() const { return EPrecedence::UNARY; }
    void AUnaryOperator::SetExpression(AExpression* expression) { m_expression = expression; }

}
