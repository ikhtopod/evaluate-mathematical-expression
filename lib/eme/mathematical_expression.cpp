#include "mathematical_expression.h"


namespace reclue {

    MathematicalExpression::MathematicalExpression(const std::string_view& sequence) :
            m_tokenSequence { sequence },
            m_scope { new Scope {}},
            m_result { 0.0 } {
        m_scope->Interpret(m_tokenSequence);
        m_result = m_scope->Calculate();
    }

    MathematicalExpression::~MathematicalExpression() { delete m_scope; }

    double MathematicalExpression::Evaluate() { return m_result; }

} // namespace reclue
