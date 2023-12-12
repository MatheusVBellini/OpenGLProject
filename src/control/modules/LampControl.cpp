#include "../../../include/control/modules/LampControl.h"
#include "../../../include/Camera.h"

LampControl::LampControl(Lamp* lamp) {
    speed = 1.0f;
    this->lamp = lamp;

    defFunc();

    mouse_button_func.emplace_back("left",relocate);
}

LampControl::~LampControl() = default;

void LampControl::defFunc() {

    relocate = [this](MOUSE_BUTTON_ARGS) {
        if (!action) return;
        lamp->setPos(Camera::getPosition() + Camera::getTarget());
    };

}