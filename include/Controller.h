#pragma once

#include <map>
#include <string>
#include <functional>
#include "GObject.h"

class Controller {
private:
    static std::map<std::string, int> key_table;
    static std::map<std::string, void(Controller::*)(int)> func_table;

    std::vector<std::pair<int,void(Controller::*)(int)>> key_method;
    std::vector<std::pair<int,std::function<void(int)>>> key_func;

public:
    static std::vector<Controller*> controllers;

    Controller();
    ~Controller();

    void keyCallback(int key, int scancode, int action, int mods);
    void bindKeyFunc(const std::string& key, const std::string& func);
    void bindKeyFunc(const std::string& key, const std::function<void(int)>& func);

    void printKey(int key);
};

