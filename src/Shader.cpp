#include "../include/Shader.h"
#include "../include/FileParser.h"

Shader::Shader() {
    program = 0;
}

Shader::~Shader() {
    glDeleteProgram(program);
}

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
