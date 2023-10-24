#include "../../include/control/FuncModule.h"

std::tuple<std::string, std::string, std::function<void(int, int, int, int)>> FuncModule::getModuleFuncs() {
    return module_funcs;
}
