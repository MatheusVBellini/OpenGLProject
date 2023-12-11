#pragma once
#include <glm/glm.hpp>
#include <array>
#include <string>

// illumination object
class Lamp {
private:
    glm::vec3 pos;  // light source position
    float Ia;  // ambient light intensity
    float Il;  // light source intensity

public:
    Lamp();
    ~Lamp();

    // getters
    glm::vec3 getPos();
    std::array<float,2> getCoeff();

    // setters
    void setPos(glm::vec3 pos);
    void setCoeff(const std::array<float,2>& coeff);

};

