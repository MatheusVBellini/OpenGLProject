#pragma once

#include <string>
#include <functional>

class FuncModule {
protected:
    std::tuple<std::string, std::string, std::function<void(int,int,int,int)>> module_funcs;
public:
    std::tuple<std::string, std::string, std::function<void(int,int,int,int)>> getModuleFuncs();
};
