#pragma once

#include "VertexBuffer.h"

class GObject {
private:
    VertexBuffer vb;
    VertexBuffer ib;
    std::string shader_name;

public:
    explicit GObject();
    ~GObject();

    void attachVertexBuffer(VertexBuffer& vb);
    void attachIndexBuffer(VertexBuffer& ib);
    void linkShader(std::string shader_name);

    VertexBuffer& getVertexBuffer();
    VertexBuffer& getIndexBuffer();
    std::string& getShaderName();

};

