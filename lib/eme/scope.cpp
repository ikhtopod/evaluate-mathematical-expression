#include "scope.h"


namespace reclue {

    EPrecedence Scope::Precedence() const { return EPrecedence::EMPTY; }
    double Scope::Calculate() const { return 0.0; }

}
