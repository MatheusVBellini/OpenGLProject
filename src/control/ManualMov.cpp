#include "../../include/control/ManualMov.h"

ManualMov::ManualMov() {
    i = 0;
    module_funcs.emplace_back("w",test);
}

ManualMov::~ManualMov() = default;
