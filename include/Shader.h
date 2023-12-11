#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
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

    void setUniformMatrix4fv(const std::string& name, const glm::mat4& matrix);

    void setUniform3f(const std::string& name, const glm::vec3& vec);
    void setUniform1i(const std::string& name, int value);
    void setUniform1f(const std::string& name, float value);

    Shader copy() const;

};
