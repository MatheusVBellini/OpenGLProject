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
    explicit VertexBuffer(BUFFER_TYPE type);
    ~VertexBuffer();

    void generate(const std::vector<float>& data);
    void generate(const std::vector<int>& data);
    void bind();

};