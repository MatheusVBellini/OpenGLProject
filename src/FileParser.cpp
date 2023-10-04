#include "../include/FileParser.h"

std::ifstream FileParser::readFile(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Unable to open: " << filepath << std::endl;
        exit(1);
    }

    return file;
}

std::tuple<std::string, std::string> FileParser::glslParse(const std::string& filepath) {
    std::ifstream file = readFile(filepath);

    int vertex = 0;
    std::string vertex_shader;

    int fragment = 0;
    std::string fragment_shader;

    std::string line;
    std::string* stream = nullptr;
    while (std::getline(file,line)) {

        // select which shader is being read
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                vertex = 1;
                stream = &vertex_shader;
                continue;
            } else if (line.find("fragment") != std::string::npos) {
                fragment = 1;
                stream = &fragment_shader;
                continue;
            }
        }

        // store shader code
        *stream += line + "\n";
    }

    if (vertex + fragment != 2) {
        std::cerr << "Unable to parse shader: " << filepath << std::endl;
        exit(1);
    }

    return {vertex_shader, fragment_shader};

}


