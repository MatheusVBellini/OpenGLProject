#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include "GObject.h"

class GObjectFactory {
private:
    typedef enum {IDLE, VERTEX, COMPOSE, TEXTURE, NORMAL, INDEX, SHADER, FINISHED} STATE;

    static bool with_texture;

    static STATE state;
    static std::vector<glm::vec3> vertex_data;
    static std::vector<unsigned int> index_data;
    static std::vector<ComposedCoord> composed_data;
    static std::string texture_filename;
    static std::string shader_name;

    static void errorMsg(const std::string& msg);

public:

    static void initProduction(bool with_texture = true);
    static void setVertexBuffer(std::vector<glm::vec3>& data);
    static void setComposedBuffer(std::vector<ComposedCoord>& data);
    static void setTexture(const std::string& filename);
    static void setNormals(std::vector<glm::vec3>& data);
    static void setIndexBuffer(std::vector<unsigned int> &data);
    static void setShader(const std::string& shader_name);
    static GObject getObject();

    static GObject genObjectFromFile(const std::string& obj_name, const std::string& texture_name);

};
