#pragma once

#include <string>
#include <functional>
#include "../GObject.h"

class FuncModule {
protected:
    std::vector<std::pair<std::string, std::function<void(int,int,int,int,GObject*)>>> module_funcs;
public:
    std::vector<std::pair<std::string, std::function<void(int,int,int,int,GObject*)>>> getModuleFuncs();
};
