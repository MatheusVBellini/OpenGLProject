#include "../../include/control/Controller.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

std::vector<Controller*> Controller::controllers;

Controller::Controller() {
    Controller::controllers.push_back(this);
    object = nullptr;
}

Controller::~Controller() = default;

void Controller::callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    for (auto& controller : Controller::controllers) {
        controller->keyCallback(key, scancode, action, mods);
    }
}

void Controller::keyCallback(int key, int scancode, int action, int mods) {
    for (auto& [key_code, func] : key_method) {
        if (key == key_code) (this->*func)(key,scancode,action,mods);
    }
    for (auto& [key_code, func] : key_func) {
        if (key == key_code) func(key,scancode,action,mods,object);
    }
}

void Controller::bindObject(GObject &object) {
    this->object = &object;
}

void Controller::loadModule(FuncModule &module) {
    this->module = &module;

    for (auto& [key, func] : this->module->getModuleFuncs()) {
        key_func.emplace_back(key_table.at(key),func);
    }
}

void Controller::unloadCurrentModule() {
    for (auto& [key, func] : this->module->getModuleFuncs()) {

        int key_code = key_table.at(key);

        for (auto it = key_func.begin(); it != key_func.end(); ) {
            if (key_code == it->first) {
                key_func.erase(it);
                break;
            }

            it++;
        }

    }
}

void Controller::bindKeyFunc(const std::string &key, const std::string &func) {
    key_method.emplace_back(
        key_table.at(key),
        func_table.at(func)
    );
}

void Controller::bindKeyFunc(const std::string &key, const std::function<void(int,int,int,int,GObject*)>& func) {
    key_func.emplace_back(
       key_table.at(key),
       func
    );
}

std::map<std::string, void(Controller::*)(int,int,int,int)> Controller::func_table = {
        {"debug", &Controller::debug}
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

void Controller::debug(int key, int scancode, int action, int mods) {
    std::cout << "Key: " << key << std::endl
              << "Scancode: " << scancode << std::endl
              << "Action: " << action << std::endl
              << "Mods: " << mods << std::endl;
}












