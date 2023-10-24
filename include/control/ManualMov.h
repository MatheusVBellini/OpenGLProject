#pragma once

#include "FuncModule.h"

class ManualMov : public FuncModule {
public:
    ManualMov();
    ~ManualMov();

    int i;

private:
    void defFuncs();

    std::function<void(int,int,int,int,GObject*)> test;
};
