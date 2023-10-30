#include "../include/GObject.h"

GObject::GObject() {
    pivot = glm::vec3(0.0f);
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

void GObject::setPivot(glm::vec3& pivot) {
    this->pivot;
}

glm::vec3 GObject::getPivot() {
    return pivot;
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





