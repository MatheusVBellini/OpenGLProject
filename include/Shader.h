#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <array>

class Shader {
private:
    unsigned program;

    void validateShader(unsigned shader);
    int getUniform(const std::string& name) const;

public:
    explicit Shader();
    ~Shader();

    void compile(const std::string& filename);
    void bind() const;
    void setUniformMatrix4fv(const std::string& name, const std::array<float,16>& matrix);

};
