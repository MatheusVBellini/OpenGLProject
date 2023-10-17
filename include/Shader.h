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

    // constructor for copies
    explicit Shader(unsigned program);

public:
    explicit Shader();
    ~Shader();

    void compile(const std::string& filename);
    void bind() const;
    void unbind() const;
    void setUniformMatrix4fv(const std::string& name, const std::array<float,16>& matrix);
    void setUniform4f(const std::string& name, const std::array<float,4>& array);
    Shader copy() const;

};
