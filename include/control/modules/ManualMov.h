#pragma once

#include "../FuncModule.h"

class ManualMov : public FuncModule {
public:
    ManualMov();
    ~ManualMov();

    float v; // speed
    float t; // angular speed

private:
    void defFuncs();

    // wasd movement
    std::function<void(int,int,int,int,GObject*)> moveLeft;
    std::function<void(int,int,int,int,GObject*)> moveRight;
    std::function<void(int,int,int,int,GObject*)> moveUp;
    std::function<void(int,int,int,int,GObject*)> moveDown;

    // rotation with arrows
    std::function<void(int,int,int,int,GObject*)> rotateXACW;
    std::function<void(int,int,int,int,GObject*)> rotateXCW;
    std::function<void(int,int,int,int,GObject*)> rotateYACW;
    std::function<void(int,int,int,int,GObject*)> rotateYCW;
};
