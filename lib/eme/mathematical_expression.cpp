#include "mathematical_expression.h"


namespace reclue {

    MathematicalExpression::MathematicalExpression(const std::string_view& sequence) :
            m_symbolSequence { sequence },
            m_scope { new Scope { nullptr }},
            m_result { 0.0 } {
        m_scope->Interpret(m_symbolSequence);
        m_result = m_scope->Calculate();
    }

    MathematicalExpression::~MathematicalExpression() { delete m_scope; }

    double MathematicalExpression::Evaluate() { return m_result; }

} // namespace reclue
