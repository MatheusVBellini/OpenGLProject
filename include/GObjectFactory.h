#pragma once

#include <iostream>
#include "GObject.h"

class GObjectFactory {
private:
    typedef enum {IDLE, VERTEX, INDEX, SHADER, FINISHED} STATE;

    static STATE state;
    static std::vector<uv> vertex_data;
    static std::vector<unsigned int> index_data;
    static std::string shader_name;

    void static errorMsg(const std::string& msg);

public:

    static void initProduction();
    static void setVertexBuffer(std::vector<uv> &data);
    static void setIndexBuffer(std::vector<unsigned int> &data);
    static void setShader(const std::string& shader_name);
    static GObject getObject();

    static GObject genObjectFromFile(const std::string& name);

};
