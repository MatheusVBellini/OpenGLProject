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
    double boundary; // space boundaries

    // keyboard movement variables
    double speed;

public:
    CameraMov(float skybox_size = 100);
    ~CameraMov();

    void defFuncs();

    // mouse rotation
    std::function<void(MOUSE_POS_ARGS)> mouseControl;

    // camera movement with keyboard
    std::function<void(KEY_ARGS)> moveForward;
    std::function<void(KEY_ARGS)> moveBack;
    std::function<void(KEY_ARGS)> moveRight;
    std::function<void(KEY_ARGS)> moveLeft;
    std::function<void(KEY_ARGS)> moveUp;
    std::function<void(KEY_ARGS)> moveDown;

};
