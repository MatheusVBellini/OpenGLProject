#include "../../../include/control/modules/CameraMov.h"

CameraMov::CameraMov() {
    // mouse
    last_x = 0.0f;
    last_y = 0.0f;
    yaw = -90.0f;
    pitch = 0.0f;
    sensitivity = 0.5f;

    // keyboard
    speed = 0.1f;

    defFuncs();

    mouse_pos_func.push_back(mouseControl);
    key_func.emplace_back("w",moveForward);
    key_func.emplace_back("s",moveBack);
    key_func.emplace_back("d",moveRight);
    key_func.emplace_back("a",moveLeft);
    key_func.emplace_back("space",moveUp);
    key_func.emplace_back("c",moveDown);

}

CameraMov::~CameraMov() = default;

void CameraMov::defFuncs() {

    mouseControl = [this](MOUSE_POS_ARGS){
        if (!mouse_started) {
            mouse_started = true;
            last_x = xpos;
            last_y = ypos;
        }

        // relative cursor movement
        double x_offset = xpos - last_x;
        double y_offset = ypos - last_y;
        last_x = xpos;
        last_y = ypos;

        // dimensioning according to sensitivity
        x_offset *= sensitivity;
        y_offset *= sensitivity;

        // change yaw and pitch
        yaw += x_offset;
        pitch -= y_offset;

        // check bounds
        pitch = (pitch >= 89.5f) ? 89.5f : pitch;
        pitch = (pitch <= -89.5f) ? -89.5f : pitch;

        // calculate new target
        // (x,y,z) = (cos(theta)*cos(phi), sin(phi), sin(theta)*cos(phi))
        glm::vec3 target;
        target.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        target.y = sin(glm::radians(pitch));
        target.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        target = glm::normalize(target);

        // update to new target
        cam.updateTarget(target);

    };

    moveForward = [this](KEY_ARGS) {
        if (!action) return;
        glm::vec3 target = cam.getTarget();
        glm::vec3 position = cam.getPosition() + ((float)speed) * target;
        cam.updatePosition(position);
    };

    moveBack = [this](KEY_ARGS) {
        if (!action) return;
        glm::vec3 target = cam.getTarget();
        glm::vec3 position = cam.getPosition() - ((float)speed) * target;
        cam.updatePosition(position);
    };

    moveRight = [this](KEY_ARGS) {
        if (!action) return;
        glm::vec3 target = glm::normalize(glm::cross(cam.getTarget(),cam.getCameraUp()));
        glm::vec3 position = cam.getPosition() + ((float)speed) * target;
        cam.updatePosition(position);
    };

    moveLeft = [this](KEY_ARGS) {
        if (!action) return;
        glm::vec3 target = glm::normalize(glm::cross(cam.getCameraUp(),cam.getTarget()));
        glm::vec3 position = cam.getPosition() + ((float)speed) * target;
        cam.updatePosition(position);
    };

    moveUp = [this](KEY_ARGS) {
        if (!action) return;
        glm::vec3 target = cam.getCameraUp();
        glm::vec3 position = cam.getPosition() + ((float)speed) * target;
        cam.updatePosition(position);
    };

    moveDown = [this](KEY_ARGS) {
        if (!action) return;
        glm::vec3 target = -cam.getCameraUp();
        glm::vec3 position = cam.getPosition() + ((float)speed) * target;
        cam.updatePosition(position);
    };

}
