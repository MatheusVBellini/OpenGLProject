#include "../../include/control/FuncModule.h"

std::vector<std::pair<std::string, std::function<void(int,int,int,int,GObject*)>>> FuncModule::getKeyFuncs() {
    return key_func;
}

std::vector<std::pair<std::string, std::function<void(int, int, int, GObject *)>>> FuncModule::getMouseButtonsFuncs() {
    return mouse_button_func;
}

std::vector<std::function<void(double, double, GObject *)>> FuncModule::getMousePosFuncs() {
    return mouse_pos_func;
}

std::vector<std::function<void(GObject *)>> FuncModule::getAutoFuncs() {
    return auto_func;
}
