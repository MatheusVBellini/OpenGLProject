#pragma once

#include "VertexBuffer.h"
#include "Texture.h"

class GObject {
private:

    // construction attributes
    VertexBuffer vb;
    VertexBuffer ib;
    std::string shader_name;
    std::string texture_filename;

    // position attributes
    glm::vec3 pivot;
    glm::mat4 movement;

public:
    explicit GObject();
    ~GObject();

    void attachVertexBuffer(VertexBuffer& vb);
    void attachIndexBuffer(VertexBuffer& ib);
    void linkShader(const std::string& shader_name);
    void linkTexture(const std::string& texture_filename);

    void setPivot(glm::vec3& pivot);
    void setMovement(glm::mat4& movement);

    glm::vec3 getPivot();
    glm::mat4 getMovement();
    VertexBuffer& getVertexBuffer();
    VertexBuffer& getIndexBuffer();
    std::string& getShaderName();
    std::string& getTextureFilename();

};

