#include "../include/GObject.h"

GObject::GObject() = default;

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


