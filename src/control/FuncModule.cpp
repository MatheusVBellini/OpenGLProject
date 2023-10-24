#include "../../include/control/FuncModule.h"

std::vector<std::pair<std::string, std::function<void(int,int,int,int,GObject*)>>> FuncModule::getModuleFuncs() {
    return module_funcs;
}
