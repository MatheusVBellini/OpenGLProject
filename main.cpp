#include <iostream>
#include "include/Application.h"
#include "include/Shader.h"
#include "include/VertexBuffer.h"
#include "include/Renderer.h"

int main() {
    // boot-up
    Application app = Application::getInstance();
    Window window(800, 800, "Hello World");
    Renderer ren;
    app.bindRenderer(ren);
    app.bindWindow(window);
    app.showWindow();

    // shader fetching and compilation
    ren.compileShaders();

    // drawing a triangle
    GObject object1;
    VertexBuffer vb1;
    VertexBuffer ib1;

    vb1.attachVertexData({
                                {-0.5,-0.5, 0},
                                {0, 0.5, 0},
                                {0.5,-0.5, 0}
                        });
    ib1.attachIndexData({0, 1, 2});
    object1.attachVertexBuffer(vb1);
    object1.attachIndexBuffer(ib1);
    object1.linkShader("simple");
    ren.registerObject(window, object1);

    // main loop
    app.init();

    return 0;
}
