#include "../include/Lamp.h"

int Lamp::light_sources = 0;

Lamp::Lamp() {
    pos = {0.0,1.0,0.0};
    ka = 1;
    kd = 0;

    name = std::to_string(light_sources);
    light_sources++;
}

Lamp::~Lamp() {

}

glm::vec3 Lamp::getPos() {
    return pos;
}

std::array<float, 2> Lamp::getCoeff() {
    return {ka, kd};
}

std::string Lamp::getName() {
    return name;
}

void Lamp::setPos(glm::vec3 pos) {
    this->pos = pos;
}

void Lamp::setCoeff(const std::array<float, 2> &coeff) {
    ka = coeff.at(0);
    kd = coeff.at(1);
}




