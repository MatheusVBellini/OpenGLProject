#include "../include/VertexBuffer.h"


VertexBuffer::VertexBuffer() {
    id = 0;
    size = 0;
    type = UNKNOWN;
}

VertexBuffer::~VertexBuffer() = default;

void VertexBuffer::attachVertexData(const std::vector<uv> &data) {
    type = VERTEX;
    size = data.size();

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    unsigned buffer_id;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(uv), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(uv), (void*) 0);
    glEnableVertexAttribArray(0);

}

void VertexBuffer::attachIndexData(const std::vector<unsigned int> &data) {
    type = INDEX;
    size = data.size();

    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), data.data(), GL_DYNAMIC_DRAW);
}

void VertexBuffer::bind() {
    if (type == VERTEX) { glBindVertexArray(id); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id); }
}

void VertexBuffer::unbind() {
    if (type == VERTEX) { glBindVertexArray(0); }
    else if (type == INDEX) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
}

unsigned VertexBuffer::getSize() const {
    return size;
}












