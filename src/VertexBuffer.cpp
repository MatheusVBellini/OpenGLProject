#include "../include/VertexBuffer.h"

VertexBuffer::VertexBuffer() {
    id = 0;
    type = VERTEX;
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);
}

void VertexBuffer::bind() {
    if (type == VERTEX) { glBindVertexArray(id); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); }
}

void VertexBuffer::genIndexBuffer(const std::vector<float> &data) {
    type = INDEX;

    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_DYNAMIC_DRAW);

}

void VertexBuffer::genVertexBuffer(const std::vector<float> &data) {
    type = VERTEX;

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_DYNAMIC_DRAW);

}




