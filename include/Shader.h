#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Shader {
private:
    unsigned program;

    void validateShader(unsigned shader);

public:
    explicit Shader();
    ~Shader();

    void compile(const std::string& filename);
    void bind();
};
