#pragma once

#include <map>
#include <string>
#include <functional>
#include "../GObject.h"

class Controller {
private:
    static std::vector<Controller*> controllers;
    static std::map<std::string, int> key_table;
    static std::map<std::string, void(Controller::*)(int,int,int,int)> func_table;

    std::vector<std::pair<int,void(Controller::*)(int,int,int,int)>> key_method;
    std::vector<std::pair<int,std::function<void(int,int,int,int)>>> key_func;

    GObject* object;

public:
    static void callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    Controller();
    ~Controller();

    void control(GObject& object);

    void keyCallback(int key, int scancode, int action, int mods);
    void bindKeyFunc(const std::string& key, const std::string& func);
    void bindKeyFunc(const std::string& key, const std::function<void(int,int,int,int)>& func);

    void debug(int key, int scancode, int action, int mods);
};

