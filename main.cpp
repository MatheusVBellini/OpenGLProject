#include <iostream>
#include "include/Application.h"
#include "include/Shader.h"
#include "include/VertexBuffer.h"
#include "include/Renderer.h"

int main() {
    // boot-up
    Application app = Application::getInstance();
    Window window(800, 800, "Hello World");
    app.bindWindow(window);
    app.showWindow();

    // shader
    Shader shader;
    shader.compile("simple");

    // Renderer test
    Renderer ren;
    ren.compileShaders();

    // drawing a triangle
    shader.bind();
    VertexBuffer vb;
    vb.attachVertexData({
        {-0.5,-0.5, 0},
        {0, 0.5, 0},
        {0.5,-0.5, 0}
    });
    VertexBuffer iv;
    iv.attachIndexData({0, 1, 2});
    shader.bindBuffers();

    vb.bind();
    iv.bind();
    shader.setUniform4f("color", {1,0,1,1});

    app.init();

    return 0;
}
