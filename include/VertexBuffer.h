#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include "CustomStructs.h"

class VertexBuffer {
private:
    typedef enum {VERTEX, INDEX, UNKNOWN} BUFFER_TYPE;

    unsigned id;
    BUFFER_TYPE type;
    unsigned long size;

public:
    explicit VertexBuffer();
    ~VertexBuffer();

    void attachVertexData(const std::vector<uv>& data);
    void attachIndexData(const std::vector<unsigned>& data);
    void bind();
    void unbind();
    unsigned getSize() const;

};