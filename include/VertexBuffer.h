#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

typedef struct { float x,y,z; } uv;

class VertexBuffer {
private:
    typedef enum {VERTEX, INDEX} BUFFER_TYPE;

    unsigned id;
    BUFFER_TYPE type;

public:
    explicit VertexBuffer(const std::vector<uv>& data);
    explicit VertexBuffer(const std::vector<unsigned>& data);
    ~VertexBuffer();

    void bind();
    void unbind();

};