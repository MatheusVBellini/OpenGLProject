#pragma once

#include "FuncModule.h"

class ManualMov : public FuncModule {
public:
    ManualMov();
    ~ManualMov();

    int i;

private:
    std::function<void(int,int,int,int,GObject*)> test = [this](int key, int scancode, int action, int mods, GObject*) {
        if (!action) return;
        this->i++;
        std::cout << this->i << std::endl;
    };
};
