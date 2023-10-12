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

            // remove ".shader" if .shader file and save it in shader_names
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

    std::cout << "<Renderer> "  << shaders.size() << " shaders compiled successfully!" << std::endl;

}

void Renderer::registerObject(GObject &object) {
    shaders[object.getShaderName()].bindBuffers();
}

void Renderer::draw(GObject& object) {

    // get variables
    VertexBuffer& vb = object.getVertexBuffer();
    VertexBuffer& ib = object.getIndexBuffer();
    std::string& shader_name = object.getShaderName();
    Shader& shader = shaders[shader_name];

    // bind variables
    vb.bind();
    ib.bind();
    shader.bind();

    // set uniforms
    shader.setUniform4f("color", {1,0,1,1});

    // draw on screen
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

    // unbind variables
    vb.unbind();
    ib.unbind();
    shader.unbind();

}

