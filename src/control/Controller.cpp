#include "../../include/control/Controller.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

std::vector<Controller*> Controller::controllers;

Controller::Controller() {
    Controller::controllers.push_back(this);
    object = nullptr;
}

Controller::~Controller() = default;

void Controller::keyEventHandler(GLFWwindow *window, int key, int scancode, int action, int mods) {
    for (auto& controller : Controller::controllers) {
        controller->keyCallback(key, scancode, action, mods);
    }
}

void Controller::mouseButtonEventHandler(GLFWwindow *window, int button, int action, int mods) {
    for (auto& controller : Controller::controllers) {
        controller->mouseButtonCallback(button, action, mods);
    }
}

void Controller::mousePositionHandler(GLFWwindow *window, double xpos, double ypos) {
    for (auto& controller : Controller::controllers) {
        controller->mousePositionCallback(xpos, ypos);
    }
}

void Controller::automaticEventHandler() {
    for (auto& controller : Controller::controllers) {
        controller->updateAutomatics();
    }
}

void Controller::keyCallback(int key, int scancode, int action, int mods) {
    for (auto& [key_code, func] : key_func) {
        if (key == key_code) func(key,scancode,action,mods,object);
    }
}

void Controller::mouseButtonCallback(int button, int action, int mods) {
    for (auto& [button_code, func] : mouse_button_func) {
        if (button == button_code) func(button,action,mods,object);
    }
}

void Controller::mousePositionCallback(double xpos, double ypos) {
    for (auto& func : mouse_pos_func) {
        func(xpos,ypos,object);
    }
}

void Controller::updateAutomatics() {
    for (auto& func : auto_func) {
        func(object);
    }
}

void Controller::bindObject(GObject &object) {
    this->object = &object;
}

void Controller::loadModule(FuncModule &module) {

    // load key events
    for (auto& [key, func] : module.getKeyFuncs()) {

        key_func.emplace_back(key_table.at(key),func);

    }

    // load mouse button events
    for (auto& [button, func] : module.getMouseButtonsFuncs()) {

        int button_code = -1;
        for (auto& [table_button, code] : mouse_buttons) {
            if (button == table_button) button_code = code;
        }

        mouse_button_func.emplace_back(button_code, func);
    }

    // load mouse pos events
    for (auto& func : module.getMousePosFuncs()) {
        mouse_pos_func.push_back(func);
    }

    // load automatic events
    for (auto& func : module.getAutoFuncs()) {
        auto_func.push_back(func);
    }

}

void Controller::setKeyFunc(const std::string &event, const std::function<void(int, int, int, int, GObject*)>& func) {
    if (key_table.find(event) == key_table.end()) {
        errorMsg("No keyboard key with the specified signature.");
        return;
    }

    key_func.emplace_back(key_table.at(event),func);
}

void Controller::setMouseButtonFunc(const std::string &event, const std::function<void(int, int, int, GObject *)> &func) {
    int button_code = -1;
    for (auto& [button, code] : mouse_buttons) {
        if (event == button) button_code = code;
    }

    if (button_code == -1) {
        errorMsg("No mouse button with the specified signature.");
        return;
    }

    mouse_button_func.emplace_back(button_code, func);
}

void Controller::setMousePosFunc(const std::function<void(double, double, GObject *)> &func) {
    mouse_pos_func.push_back(func);
}

void Controller::setAutoFunc(const std::function<void(GObject *)> &func) {
    auto_func.push_back(func);
}

std::array<std::pair<std::string,int>,3> Controller::mouse_buttons = {
        std::make_pair("left", GLFW_MOUSE_BUTTON_LEFT),
        std::make_pair("right", GLFW_MOUSE_BUTTON_RIGHT),
        std::make_pair("middle", GLFW_MOUSE_BUTTON_MIDDLE)
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

void Controller::errorMsg(const std::string &msg) {
    std::cerr << "<Controller> " << msg << std::endl;
}





























