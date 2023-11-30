#include "../include/GObject.h"

GObject::GObject() {
    movement = glm::mat4(1.0f);
};

GObject::~GObject() = default;

void GObject::attachVertexBuffer(VertexBuffer& vb) {
    this->vb = vb;
}

void GObject::attachIndexBuffer(VertexBuffer& ib) {
    this->ib = ib;
}

void GObject::linkShader(const std::string& shader_name) {
    this->shader_name = shader_name;
}

void GObject::linkTexture(const std::string& texture_filename) {
    this->texture_filename = texture_filename;
}

VertexBuffer& GObject::getVertexBuffer() {
    return vb;
}

VertexBuffer& GObject::getIndexBuffer() {
    return ib;
}

std::string &GObject::getShaderName() {
    return shader_name;
}

std::string &GObject::getTextureFilename() {
    return texture_filename;
}

void GObject::setMovement(glm::mat4& movement) {
    this->movement = movement;
}

glm::mat4 GObject::getMovement() {
    return movement;
}

void GObject::setName(const std::string &name) {
    this->name = name;
}

std::string GObject::getName() {
    return name;
}

void GObject::setHitbox(const std::array<glm::vec3, 8>& hitbox) {
    this->hitbox = hitbox;
}

std::array<glm::vec3, 8> GObject::getHitbox() const {
    return hitbox;
}









