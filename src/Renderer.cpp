#include "../include/Renderer.h"
#include "../include/Debug.h"
#include "../include/AppConstants.h"
#include "../include/Camera.h"

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
    std::string& texture_name = object.getTextureFilename();
    Texture& texture = textures.at(texture_name).second;
    unsigned slot = textures.at(texture_name).first;

    // bind variables
    shader.bind();
    vb.bind();
    ib.bind();
    texture.bind(slot);

    // set uniforms
    shader.setUniform1i("samplerTexture", slot); // texture slot
    shader.setUniformMatrix4fv("model", object.getMovement()); // model matrix
    shader.setUniformMatrix4fv("view", Camera::getView()); // view matrix
    shader.setUniformMatrix4fv("projection", Camera::getProjection()); // projection matrix

    shader.setUniform3f("lightPos", {0,0.5,0}); // light position
    shader.setUniform1f("ka", 0.5); // ambient
    shader.setUniform1f("kd", 0.5); // diffusion

    // draw on screen
    glPolygonMode(GL_FRONT_AND_BACK, texture.getDrawType());
    glDrawElements(GL_TRIANGLES, ib.getSize(), GL_UNSIGNED_INT, nullptr);

    // unbind variables
    texture.unbind();
    ib.unbind();
    vb.unbind();
    shader.unbind();

}

Texture& Renderer::fetchTexture(const std::string& texture_name) {
    return textures.at(texture_name).second;
}






