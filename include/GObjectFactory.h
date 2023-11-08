#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include "GObject.h"

class GObjectFactory {
private:
    typedef enum {IDLE, VERTEX, COMPOSE, TEXTURE, NORMAL, INDEX, SHADER, FINISHED} STATE;

    // defines which path production must take according to texture option
    static bool with_texture;

    static STATE state; // current state of production
    static std::string name; // name of the object to be produced
    static std::vector<glm::vec3> vertex_data;
    static std::vector<unsigned int> index_data;
    static std::vector<ComposedCoord> composed_data; // vertex + texture + normal data
    static std::string texture_filename;
    static std::string shader_name;

    static void errorMsg(const std::string& msg);
    static std::array<float,6> getBoundaries(const std::vector<glm::vec3>& coords);

public:

    // object production methods
    static void initProduction(const std::string& name, bool with_texture = true); // flags the beginning of production
    static void setVertexBuffer(std::vector<glm::vec3>& data); // set simple vertex buffer (no texture)
    static void setComposedBuffer(std::vector<ComposedCoord>& data); // set composed buffer (with texture)
    static void setTexture(const std::string& filename); // loads specific texture for object
    static void setNormals(std::vector<glm::vec3>& data); // set the normals buffer (no texture)
    static void setIndexBuffer(std::vector<unsigned int> &data); // set the render index of buffers
    static void setShader(const std::string& shader_name); // set the specific shader for object
    static GObject getObject(); // returns produced object

    static GObject genObjectFromFile(const std::string& obj_name, const std::string& texture_name);

};
