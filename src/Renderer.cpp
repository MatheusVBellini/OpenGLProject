#include "../include/Renderer.h"

Renderer::Renderer() {}

Renderer::~Renderer() {}

void Renderer::findShaders() {
    std::string dir = "../data/shaders";
    std::string suffix = ".shader";
    std::string shader_name;
    size_t pos = 0;

    // search .shader files
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            shader_name = entry.path().filename();

            // remove ".shader" if .shader file e salva em shader_names
            if ((pos = shader_name.find(suffix, 0)) != std::string::npos) {
                shader_name.erase(pos, suffix.length());
                shader_names.push_back(shader_name);
            }

        }
    }

}

void Renderer::compileShaders() {
    Shader shader;
    findShaders();

    for (auto& shader_name : shader_names) {
        shader.compile(shader_name);
        shaders.insert({shader_name,shader.copy()});
    }

    std::cout << shaders.size() << std::endl;

}

