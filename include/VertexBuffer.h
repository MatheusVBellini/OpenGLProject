#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

class VertexBuffer {
private:
    typedef enum {VERTEX, INDEX} BUFFER_TYPE;

    unsigned id;
    BUFFER_TYPE type;

public:
    explicit VertexBuffer();
    ~VertexBuffer();

    void genIndexBuffer(const std::vector<float>& data);
    void genVertexBuffer(const std::vector<float>& data);
    void bind();

};