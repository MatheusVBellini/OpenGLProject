#pragma once

#include "../FuncModule.h"

class ManualMov : public FuncModule {
public:
    ManualMov();
    ~ManualMov();

    float v; // speed
    float t; // angular speed

    // return false if operation should not be done, true otherwise
    bool checkBoundaries(const glm::mat4& mat, const GObject* obj);

private:
    void defFuncs();

    // wasd movement
    std::function<void(KEY_ARGS)> moveLeft;
    std::function<void(KEY_ARGS)> moveRight;
    std::function<void(KEY_ARGS)> moveUp;
    std::function<void(KEY_ARGS)> moveDown;
    std::function<void(KEY_ARGS)> moveAway;
    std::function<void(KEY_ARGS)> moveCloser;

    // rotation with arrows
    std::function<void(KEY_ARGS)> rotateXACW;
    std::function<void(KEY_ARGS)> rotateXCW;
    std::function<void(KEY_ARGS)> rotateYACW;
    std::function<void(KEY_ARGS)> rotateYCW;

    // scale
    std::function<void(int,int,int,int,GObject*)> grow;
    std::function<void(int,int,int,int,GObject*)> shrink;

};
