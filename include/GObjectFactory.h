#pragma once

#include <iostream>
#include "GObject.h"

class GObjectFactory {
private:
    typedef enum {IDLE, VERTEX, INDEX, TEXTURE, SHADER, FINISHED} STATE;

    static bool with_texture;

    static STATE state;
    static std::vector<uv> vertex_data;
    static std::vector<unsigned int> index_data;
    static std::string texture_filename;
    static std::string shader_name;

    void static errorMsg(const std::string& msg);

public:

    static void initProduction(bool with_texture = true);
    static void setVertexBuffer(std::vector<uv> &data);
    static void setIndexBuffer(std::vector<unsigned int> &data);
    static void setTexture(const std::string& filename, std::vector<uv_texture>& data);
    static void setShader(const std::string& shader_name);
    static GObject getObject();

    static GObject genObjectFromFile(const std::string& name);

};
