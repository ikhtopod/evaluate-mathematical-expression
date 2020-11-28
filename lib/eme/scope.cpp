#include "scope.h"


namespace reclue {

    Scope::Scope() : m_expression {} {}
    Scope::~Scope() { delete m_expression; }

    EPrecedence Scope::Precedence() const { return EPrecedence::SCOPE; }
    double Scope::Calculate() const { return m_expression->Calculate(); }

    void Scope::SetExpression(AExpression* expression) { m_expression = expression; }

}
