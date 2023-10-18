#include "../include/Renderer.h"
#include "../include/Debug.h"
#include "../include/AppConstants.h"

Renderer::Renderer() = default;

Renderer::~Renderer() = default;

void Renderer::findShaders() {
    std::string dir = "../data/shaders";
    std::string suffix = ".shader";
    std::string shader_name;
    size_t pos = 0;

    // search .shader files
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            shader_name = entry.path().filename();

            // remove ".shader" if .shader file and save it in shader_names
            if ((pos = shader_name.find(suffix, 0)) != std::string::npos) {
                shader_name.erase(pos, suffix.length());
                shader_names.push_back(shader_name);
            }

        }
    }

}

void Renderer::findTextures() {
    std::string dir = "../data/textures";
    std::string texture_name;
    size_t pos = 0;

    // search .shader files
    for (const auto& entry : std::filesystem::directory_iterator(dir)) {
        if (entry.is_regular_file()) {
            texture_name = entry.path().filename();
            texture_names.push_back(texture_name);
        }
    }

}

void Renderer::compileShaders() {
    Shader shader;
    findShaders();

    for (auto& shader_name : shader_names) {
        shader.compile(shader_name);
        shaders.insert({shader_name,shader});
    }

    std::cout << "<Renderer> "  << shaders.size() << " shaders compiled successfully!" << std::endl;

}

void Renderer::loadTextures() {
    Texture texture;
    findTextures();
    unsigned slot = 0;

    for (auto& texture_name : texture_names) {
        texture.load(texture_name);
        textures.insert({texture_name,{slot,texture}});
        slot++;
        slot %= TEXTURE_SLOT_MAX;
    }

    std::cout << "<Renderer> "  << textures.size() << " textures loaded successfully!" << std::endl;

}

void Renderer::draw(GObject& object) {
    // get variables
    VertexBuffer& vb = object.getVertexBuffer();
    VertexBuffer& ib = object.getIndexBuffer();
    std::string& shader_name = object.getShaderName();
    Shader& shader = shaders.at(shader_name);

    // bind variables
    vb.bind();
    ib.bind();
    shader.bind();

    // set uniforms
    shader.setUniform4f("color", {1,0,1,1});

    // draw on screen
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawElements(GL_TRIANGLES, ib.getSize(), GL_UNSIGNED_INT, nullptr);

    // unbind variables
    vb.unbind();
    ib.unbind();
    shader.unbind();
}





