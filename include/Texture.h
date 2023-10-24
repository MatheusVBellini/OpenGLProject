#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include <vector>
#include "vendor/stb_image.h"

class Texture {
private:

    unsigned id;
    int width;
    int height;
    int bpp;

public:
    Texture();
    ~Texture();

    void load(const std::string& filename);
    void attachTextureData(std::vector<glm::vec2> &data);
    void bind(unsigned slot = 0);
    void unbind();

};

