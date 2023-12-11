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
    float ks;  // specular reflection coefficient
    float ns;  // specular reflection exponent

public:
    Lamp();
    ~Lamp();

    // getters
    glm::vec3 getPos();
    std::array<float,3> getCoeff();
    float getSpecExp();

    // setters
    void setPos(glm::vec3 pos);
    void setCoeff(const std::array<float,3>& coeff);
    void setSpecExp(float ns);

};

