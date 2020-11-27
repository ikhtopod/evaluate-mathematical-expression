#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "calc.hpp"


int main() {
    std::vector<std::string> ex {
            { "1 + 1" },
            { "3 -(-1)" },
            { "-7 * -(6 / 3)" },
            { "−(23) + −7 − (−2) * −(6 / 3)" },
            { "−(2.3) + −7 − (−2) * −(6 / 3)" },
    };

    for (const auto& e : ex) {
        std::cout << e << " = " << reclue::calc(e) << std::endl;
    }

    return EXIT_SUCCESS;
}
