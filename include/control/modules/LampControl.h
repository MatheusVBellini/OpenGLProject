#pragma once

#include "../FuncModule.h"
#include "../../Lamp.h"

class LampControl : public FuncModule {
private:
    float dI; // pace of change in light intensity
    Lamp* lamp;

public:
    explicit LampControl(Lamp* lamp);
    ~LampControl();

    void defFunc();

    // set the position of the light source to the position the cameras is currently looking
    std::function<void(MOUSE_BUTTON_ARGS)> relocate;

    // light intensity control
    std::function<void(KEY_ARGS)> ambient_up; // more ambient light
    std::function<void(KEY_ARGS)> ambient_down; // less ambient light
    std::function<void(KEY_ARGS)> reflection_up; // more intensity from light source
    std::function<void(KEY_ARGS)> reflection_down; // less intensity from light source

};
