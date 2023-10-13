#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <iostream>
#include <map>
#include "Shader.h"
#include "GObject.h"

class Renderer {
private:
    unsigned current_object;

    std::vector<std::string> shader_names;
    std::unordered_map<std::string, Shader> shaders;

    void findShaders();

public:
    explicit Renderer();
    ~Renderer();

    void compileShaders();
    void registerObject(GObject& object);
    void draw(GObject& object);

};

