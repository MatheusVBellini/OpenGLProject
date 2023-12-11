#pragma once
#include <glm/glm.hpp>
#include <array>
#include <string>

// illumination object
class Lamp {
private:
    static int light_sources; // counter to be used as identifier

    glm::vec3 pos; // light source position
    float ka;  // ambient light coefficient
    float kd;  // diffuse reflection coefficient

    std::string name;  // string identifier for the light source

public:
    Lamp();
    ~Lamp();

    // getters
    glm::vec3 getPos();
    std::array<float,2> getCoeff();
    std::string getName();

    // setters
    void setPos(glm::vec3 pos);
    void setCoeff(const std::array<float,2>& coeff);

};

