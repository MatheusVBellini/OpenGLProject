#include "../../include/control/ManualMov.h"

ManualMov::ManualMov() {
    i = 0;

    defFuncs();
    module_funcs.emplace_back("w",test);
}

ManualMov::~ManualMov() = default;

void ManualMov::defFuncs() {
    test = [this](int key, int, int action, int, GObject*) {
        if (!action) return;
        this->i++;
        std::cout << this->i << std::endl;
    };
}