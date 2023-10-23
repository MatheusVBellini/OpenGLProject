#include <iostream>
#include "../include/Texture.h"
#include "../include/AppConstants.h"

Texture::Texture() {
    id = 0;
    width = 0;
    height = 0;
    bpp = 0;
}

Texture::~Texture() = default;

void Texture::load(const std::string& filename) {
    std::string filepath = "../data/textures/" + filename;

    stbi_set_flip_vertically_on_load(1);
    auto buffer = stbi_load(filepath.c_str(), &width, &height, &bpp, 4);


    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    unbind();

    if (buffer) stbi_image_free(buffer);
}

void Texture::attachTextureData(std::vector<glm::vec2> &data) {
    unsigned buffer;

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(TEXTURE_SLOT, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*) 0);
    glEnableVertexAttribArray(TEXTURE_SLOT);
}

void Texture::bind(unsigned int slot) {
    slot %= TEXTURE_SLOT_MAX;
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D,0);
}


