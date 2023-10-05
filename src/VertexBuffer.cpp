#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(BUFFER_TYPE type) {
    id = 0;
    type = type;
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);
}

void VertexBuffer::generate(const std::vector<float> &data) {
    glGenBuffers(1, &id);

    auto gl_buffer_type = (type == VERTEX) ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER;

    glBindBuffer(gl_buffer_type, id);
    glBufferData(gl_buffer_type, data.size() * sizeof(float), data.data(), GL_DYNAMIC_DRAW);
}

void VertexBuffer::generate(const std::vector<int> &data) {}

void VertexBuffer::bind() {
    auto gl_buffer_type = (type == VERTEX) ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER;
    glBindBuffer(gl_buffer_type, id);
}




