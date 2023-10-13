#include "../include/GObject.h"

GObject::GObject() = default;

GObject::~GObject() = default;

void GObject::attachVertexBuffer(VertexBuffer& vb) {
    this->vb = vb;
}

void GObject::attachIndexBuffer(VertexBuffer& ib) {
    this->ib = ib;
}

void GObject::linkShader(std::string shader_name) {
    this->shader_name = shader_name;
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
