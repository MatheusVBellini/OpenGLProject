#include "../include/Lamp.h"

Lamp::Lamp() {
    pos = {0.0,1.0,0.0};
    ka = 1;
    kd = 0;
    ks = 1;
    ns = 10;
}

Lamp::~Lamp() = default;

glm::vec3 Lamp::getPos() {
    return pos;
}

std::array<float, 3> Lamp::getCoeff() {
    return {ka, kd, ks};
}

float Lamp::getSpecExp() {
    return ns;
}

void Lamp::setPos(glm::vec3 pos) {
    this->pos = pos;
}

void Lamp::setCoeff(const std::array<float, 3> &coeff) {
    ka = coeff.at(0);
    kd = coeff.at(1);
    ks = coeff.at(2);
}

void Lamp::setSpecExp(float ns) {
    this->ns = ns;
}





