#pragma once

#include "../FuncModule.h"
#include "../../Lamp.h"

class LampControl : public FuncModule {
private:
    float speed;
    Lamp* lamp;

public:
    explicit LampControl(Lamp* lamp);
    ~LampControl();

    void defFunc();

    // set the position of the light source to the position the cameras is currently looking
    std::function<void(MOUSE_BUTTON_ARGS)> relocate;

};
