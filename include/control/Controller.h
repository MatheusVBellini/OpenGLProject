#pragma once

#include <map>
#include <string>
#include <functional>
#include "../GObject.h"
#include "FuncModule.h"

class Controller {
private:
    static std::vector<Controller*> controllers;
    static std::map<std::string, int> key_table;
    static std::array<std::pair<std::string,int>,3> mouse_buttons;

    std::vector<std::pair<int,std::function<void(int,int,int,int,GObject*)>>> key_func;
    std::vector<std::pair<int,std::function<void(int,int,int,GObject*)>>> mouse_button_func;
    std::vector<std::function<void(double,double,GObject*)>> mouse_pos_func;
    std::vector<std::function<void(GObject*)>> auto_func;

    GObject* object;

    static void errorMsg(const std::string& msg);

public:
    Controller();
    ~Controller();

    void attachObject(GObject& object);
    void loadModule(FuncModule& module); // change

    static void keyEventHandler(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void mouseButtonEventHandler(GLFWwindow *window, int button, int action, int mods);
    static void mousePositionHandler(GLFWwindow* window, double xpos, double ypos);
    static void automaticEventHandler();

    void keyCallback(int key, int scancode, int action, int mods);
    void mouseButtonCallback(int button, int action, int mods);
    void mousePositionCallback(double xpos, double ypos);
    void updateAutomatics();

    void setKeyFunc(const std::string& event, const std::function<void(int, int, int, int, GObject*)>& func);
    void setMouseButtonFunc(const std::string& event, const std::function<void(int, int, int, GObject*)>& func);
    void setMousePosFunc(const std::function<void(double, double, GObject*)>& func);
    void setAutoFunc(const std::function<void(GObject*)>& func);

};

