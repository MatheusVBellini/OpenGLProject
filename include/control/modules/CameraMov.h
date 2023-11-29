#pragma once

#include "../../Camera.h"
#include "../FuncModule.h"

class CameraMov : public FuncModule {
private:
    Camera cam;

    // camera mouse control variables
    bool mouse_started = false; // if mouse event handles was ever called
    double last_x; // mouse last x-position
    double last_y; // mouse last y-position
    double yaw; // xz-plane rotation
    double pitch; // yz-pane rotation
    double sensitivity; // mouse sensitivity

    // keyboard movement variables
    double speed;

public:
    CameraMov();
    ~CameraMov();

    void defFuncs();

    // mouse rotation
    std::function<void(MOUSE_POS_ARGS)> mouseControl;

    // camera movement with keyboard
    std::function<void(KEY_ARGS)> moveForward;
    std::function<void(KEY_ARGS)> moveBack;

};
