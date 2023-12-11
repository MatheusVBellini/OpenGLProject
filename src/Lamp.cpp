#include "../include/Lamp.h"

Lamp::Lamp() {
    pos = {0.0,1.0,0.0};
    Ia = 1;
    Il = 0;
}

Lamp::~Lamp() = default;

glm::vec3 Lamp::getPos() {
    return pos;
}

std::array<float, 2> Lamp::getCoeff() {
    return {Ia, Il};
}

void Lamp::setPos(glm::vec3 pos) {
    this->pos = pos;
}

void Lamp::setCoeff(const std::array<float,2> &coeff) {
    Ia = coeff.at(0);
    Il = coeff.at(1);
}





