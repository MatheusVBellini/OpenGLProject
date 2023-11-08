#pragma once

#include <array>
#include "VertexBuffer.h"
#include "Texture.h"

class GObject {
private:

    // metadata
    std::string name;

    // construction attributes
    VertexBuffer vb;
    VertexBuffer ib;
    std::string shader_name;
    std::string texture_filename;

    // position attributes
    glm::mat4 movement;
    std::array<glm::vec3,8> hitbox;

public:
    explicit GObject();
    ~GObject();

    void attachVertexBuffer(VertexBuffer& vb);
    void attachIndexBuffer(VertexBuffer& ib);
    void linkShader(const std::string& shader_name);
    void linkTexture(const std::string& texture_filename);

    void setMovement(glm::mat4& movement);
    void setName(const std::string& name);
    void setHitbox(const std::array<glm::vec3,8>& hitbox);

    glm::mat4 getMovement();
    std::string getName();

    VertexBuffer& getVertexBuffer();
    VertexBuffer& getIndexBuffer();
    std::string& getShaderName();
    std::string& getTextureFilename();

    std::array<glm::vec3,8> getHitbox() const;



};

