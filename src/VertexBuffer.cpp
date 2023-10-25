#include "../include/VertexBuffer.h"
#include "../include/AppConstants.h"


VertexBuffer::VertexBuffer() {
    id = 0;
    size = 0;
    type = UNKNOWN;
}

VertexBuffer::~VertexBuffer() = default;

void VertexBuffer::attachVertexData(const std::vector<glm::vec3> &data) {
    type = VERTEX;
    size = data.size();

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    unsigned buffer_id;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(glm::vec3), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(VERTEX_SLOT, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*) 0);
    glEnableVertexAttribArray(VERTEX_SLOT);

}

void VertexBuffer::attachVertexData(const std::vector<ComposedCoord> &data) {
    type = VERTEX;
    size = data.size();

    glGenVertexArrays(1, &id);
    glBindVertexArray(id);

    unsigned buffer_id;
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(ComposedCoord), data.data(), GL_DYNAMIC_DRAW);

    // bind vertex coordinates
    glVertexAttribPointer(VERTEX_SLOT, 3, GL_FLOAT, GL_FALSE, sizeof(ComposedCoord), (GLvoid*)0);
    glEnableVertexAttribArray(VERTEX_SLOT);

    // bind texture coordinates
    glVertexAttribPointer(TEXTURE_SLOT, 2, GL_FLOAT, GL_FALSE, sizeof(ComposedCoord), (GLvoid*)(sizeof(glm::vec3)));
    glEnableVertexAttribArray(TEXTURE_SLOT);

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














