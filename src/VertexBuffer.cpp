#include "../include/VertexBuffer.h"


VertexBuffer::VertexBuffer() {
    id = 0;
    size = 0;
    type = UNKNOWN;
}

void VertexBuffer::attachVertexData(const std::vector<uv> &data) {
    type = VERTEX;
    size = data.size();

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(uv), data.data(), GL_DYNAMIC_DRAW);
}

void VertexBuffer::attachIndexData(const std::vector<unsigned int> &data) {
    type = INDEX;
    size = data.size();

    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), data.data(), GL_DYNAMIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);
}

void VertexBuffer::bind() {
    if (type == VERTEX) { glBindVertexArray(id); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); }
    else if (type == UNKNOWN) { std::cout << "Buffer not initialized. Type: UNKNOWN" << std::endl; }
}

void VertexBuffer::unbind() {
    if (type == VERTEX) { glBindVertexArray(0); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
    else if (type == UNKNOWN) { std::cout << "Buffer not initialized. Type: UNKNOWN" << std::endl; }
}

unsigned VertexBuffer::getSize() const {
    return size;
}










