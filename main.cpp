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
    GObject object;
    VertexBuffer vb;
    VertexBuffer ib;

    vb.attachVertexData({
                                {-0.5,-0.5, 0},
                                {0, 0.5, 0},
                                {0.5,-0.5, 0}
                        });
    ib.attachIndexData({0, 1, 2});
    object.attachVertexBuffer(vb);
    object.attachIndexBuffer(ib);
    object.linkShader("simple");
    ren.registerObject(window, object);

    // main loop
    app.init();

    return 0;
}
