#include "a_expression.h"


namespace reclue {

    AExpression::AExpression(AExpression* ancestor) : m_ancestor { ancestor } {}

    //AExpression::~AExpression() { delete m_ancestor; }

    bool AExpression::HasAncestor() const { return m_ancestor; }

}
