#include "../include/Controller.h"
#include <GLFW/glfw3.h>

std::vector<Controller*> Controller::controllers;

Controller::Controller() {
    Controller::controllers.push_back(this);
}

Controller::~Controller() = default;

void Controller::keyCallback(int key, int scancode, int action, int mods) {
    if (action == 0) return;
    for (auto& [key_code, func] : key_method) {
        if (key == key_code) (this->*func)(key);
    }
    for (auto& [key_code, func] : key_func) {
        if (key == key_code) func(key);
    }
}

void Controller::bindKeyFunc(const std::string &key, const std::string &func) {
    key_method.emplace_back(
        key_table.at(key),
        func_table.at(func)
    );
}

void Controller::bindKeyFunc(const std::string &key, const std::function<void(int)>& func) {
    key_func.emplace_back(
       key_table.at(key),
       func
    );
}

std::map<std::string, void(Controller::*)(int)> Controller::func_table = {
        {"printKey", &Controller::printKey}
};

std::map<std::string, int> Controller::key_table = {
        {"a", GLFW_KEY_A},
        {"b", GLFW_KEY_B},
        {"c", GLFW_KEY_C},
        {"d", GLFW_KEY_D},
        {"e", GLFW_KEY_E},
        {"f", GLFW_KEY_F},
        {"g", GLFW_KEY_G},
        {"h", GLFW_KEY_H},
        {"i", GLFW_KEY_I},
        {"j", GLFW_KEY_J},
        {"k", GLFW_KEY_K},
        {"l", GLFW_KEY_L},
        {"m", GLFW_KEY_M},
        {"n", GLFW_KEY_N},
        {"o", GLFW_KEY_O},
        {"p", GLFW_KEY_P},
        {"q", GLFW_KEY_Q},
        {"r", GLFW_KEY_R},
        {"s", GLFW_KEY_S},
        {"t", GLFW_KEY_T},
        {"u", GLFW_KEY_U},
        {"v", GLFW_KEY_V},
        {"w", GLFW_KEY_W},
        {"x", GLFW_KEY_X},
        {"y", GLFW_KEY_Y},
        {"z", GLFW_KEY_Z},
        {"space", GLFW_KEY_SPACE},
        {"enter", GLFW_KEY_ENTER},
        {"escape", GLFW_KEY_ESCAPE},
        {"left_shift", GLFW_KEY_LEFT_SHIFT}
};

void Controller::printKey(int key) {
    std::cout << "method used!" << std::endl;
}







