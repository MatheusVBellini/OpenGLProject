#include "../../../include/control/modules/LampControl.h"
#include "../../../include/Camera.h"

LampControl::LampControl(Lamp* lamp) {
    dI = 0.05f;
    this->lamp = lamp;

    defFunc();

    mouse_button_func.emplace_back("left",relocate);
    key_func.emplace_back("i", reflection_up);
    key_func.emplace_back("k", reflection_down);
    key_func.emplace_back("o", ambient_up);
    key_func.emplace_back("l", ambient_down);

}

LampControl::~LampControl() = default;

void LampControl::defFunc() {

    relocate = [this](MOUSE_BUTTON_ARGS) {
        if (!action) return;
        lamp->setPos(Camera::getPosition() + Camera::getTarget());
    };

    ambient_up = [this](KEY_ARGS) {
        if (!action) return;
        auto [Ia, Id] = lamp->getCoeff();
        Ia += dI;
        if (Ia <= 1) lamp->setCoeff({Ia,Id});
    };

    ambient_down = [this](KEY_ARGS) {
        if (!action) return;
        auto [Ia, Id] = lamp->getCoeff();
        Ia -= dI;
        if (Ia >= 0) lamp->setCoeff({Ia,Id});
    };

    reflection_up = [this](KEY_ARGS) {
        if (!action) return;
        auto [Ia, Id] = lamp->getCoeff();
        Id += dI;
        if (Id <= 1) lamp->setCoeff({Ia,Id});
    };

    reflection_down = [this](KEY_ARGS) {
        if (!action) return;
        auto [Ia, Id] = lamp->getCoeff();
        Id -= dI;
        if (Id >= 0) lamp->setCoeff({Ia,Id});
    };

}