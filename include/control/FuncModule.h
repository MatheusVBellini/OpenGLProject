#pragma once

#include <string>
#include <functional>
#include "../GObject.h"

class FuncModule {
protected:
    std::vector<std::pair<std::string,std::function<void(int,int,int,int,GObject*)>>> key_func;
    std::vector<std::pair<std::string,std::function<void(int,int,int,GObject*)>>> mouse_button_func;
    std::vector<std::function<void(double,double,GObject*)>> mouse_pos_func;
    std::vector<std::function<void(GObject*)>> auto_func;

public:
    std::vector<std::pair<std::string, std::function<void(int,int,int,int,GObject*)>>> getKeyFuncs();
    std::vector<std::pair<std::string,std::function<void(int,int,int,GObject*)>>> getMouseButtonsFuncs();
    std::vector<std::function<void(double,double,GObject*)>> getMousePosFuncs();
    std::vector<std::function<void(GObject*)>> getAutoFuncs();
};
