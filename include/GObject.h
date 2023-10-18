#pragma once

#include "VertexBuffer.h"
#include "Texture.h"

class GObject {
private:
    VertexBuffer vb;
    VertexBuffer ib;
    std::string shader_name;
    std::string texture_filename;

public:
    explicit GObject();
    ~GObject();

    void attachVertexBuffer(VertexBuffer& vb);
    void attachIndexBuffer(VertexBuffer& ib);
    void linkShader(const std::string& shader_name);
    void linkTexture(const std::string& texture_filename);

    VertexBuffer& getVertexBuffer();
    VertexBuffer& getIndexBuffer();
    std::string& getShaderName();
    std::string& getTextureFilename();

};

