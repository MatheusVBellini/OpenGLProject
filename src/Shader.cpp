#include "../include/Shader.h"
#include "../include/FileParser.h"
#include "../include/AppStructs.h"
#include <glm/gtc/type_ptr.hpp>

Shader::Shader() {
    program = 0;
}

Shader::~Shader() = default;

void Shader::compile(const std::string &filename) {
    FileParser fp;
    std::string filepath = "../data/shaders/" + filename + ".shader";

    // get shader code
    auto [vertex_shader, fragment_shader] = fp.glslParse(filepath);

    // create shader elements
    program = glCreateProgram();
    unsigned vertex = glCreateShader(GL_VERTEX_SHADER);
    unsigned fragment = glCreateShader(GL_FRAGMENT_SHADER);

    // attribute shader code to elements
    const char* vertex_code = vertex_shader.c_str();
    const char* fragment_code = fragment_shader.c_str();
    glShaderSource(vertex, 1, &vertex_code, nullptr);
    glShaderSource(fragment, 1, &fragment_code, nullptr);

    // compile the shader
    glCompileShader(vertex);
    glCompileShader(fragment);
    validateShader(vertex);
    validateShader(fragment);

    // link program
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glValidateProgram(program);

    // clean shaders
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    unbind();
}

void Shader::validateShader(unsigned shader) {
    int status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::string info(length, ' ');
        glGetShaderInfoLog(shader, info.length(), &length, &info[0]);
        std::cout << "ERROR compiling shader: " << info << std::endl;

        exit(1);
    }
}

void Shader::bind() const {
    glUseProgram(program);
}

int Shader::getUniform(const std::string &name) const {
    return glGetUniformLocation(program, name.c_str());
}

void Shader::unbind() const {
    glUseProgram(0);
}

void Shader::setUniformMatrix4fv(const std::string &name, const glm::mat4& matrix) {
    glUniformMatrix4fv(getUniform(name),1,GL_FALSE, glm::value_ptr(matrix));
}

void Shader::setUniform3f(const std::string &name, const glm::vec3& vec) {
    glUniform3f(getUniform(name), vec.x, vec.y, vec.z);
}

void Shader::setUniform1i(const std::string &name, int value) {
    glUniform1i(getUniform(name), value);
}

void Shader::setUniform1f(const std::string &name, float value) {
    glUniform1f(getUniform(name), value);
}

Shader::Shader(unsigned int program) {
    this->program = program;
}

Shader Shader::copy() const {
    return Shader(program);
}












