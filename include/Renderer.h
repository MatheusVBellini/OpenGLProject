#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <iostream>
#include <map>
#include "Shader.h"
#include "GObject.h"
#include "Window.h"

class Renderer {
private:
    std::vector<std::string> shader_names;
    std::unordered_map<std::string, Shader> shaders;

    std::vector<std::string> texture_names;
    std::unordered_map<std::string, std::pair<unsigned,Texture>> textures;

    void findShaders();
    void findTextures();

public:
    explicit Renderer();
    ~Renderer();

    void compileShaders();
    void loadTextures();
    void draw(GObject& object);

    Texture& fetchTexture(const std::string& texture_name);

};

