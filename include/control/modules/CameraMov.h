#pragma once

#include "../../Camera.h"
#include "../FuncModule.h"

class CameraMov : public FuncModule {
private:
    Camera cam;
    float r; // camera rotation speed
    float t; // camera translation speed

public:
    CameraMov();
    ~CameraMov();

    void defFuncs();

    // mouse rotation
    std::function<void(MOUSE_POS_ARGS)> mouseControl;

};
