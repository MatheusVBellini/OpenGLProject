#pragma once
#include <glm/glm.hpp>
#include <array>
#include <string>

// illumination object
class Lamp {
private:
    glm::vec3 pos;  // light source position
    float ka;  // ambient light coefficient
    float kd;  // diffuse reflection coefficient
    float ks;  // specular reflection coefficient
    float ns;  // specular reflection exponent

    std::string name;  // string identifier for the light source

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

