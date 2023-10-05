#include "../include/VertexBuffer.h"


VertexBuffer::VertexBuffer(const std::vector<uv> &data) {
    id = 0;
    type = VERTEX;

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_DYNAMIC_DRAW);

}

VertexBuffer::VertexBuffer(const std::vector<unsigned int> &data) {
    id = 0;
    type = INDEX;

    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_DYNAMIC_DRAW);

}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);
}

void VertexBuffer::bind() {
    if (type == VERTEX) { glBindVertexArray(id); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); }
}

void VertexBuffer::unbind() {
    if (type == VERTEX) { glBindVertexArray(0); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
}






