#include <iostream>
#include "include/Application.h"
#include "include/VertexBuffer.h"
#include "include/Renderer.h"
#include "include/Debug.h"

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

    // drawing triangle 1
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

    // drawing triangle 2
    GObject object2;
    VertexBuffer vb2;
    VertexBuffer ib2;

    vb2.attachVertexData({
                                 {-1,-1, 0},
                                 {-1, -0.25, 0},
                                 {-0.25,-0.25, 0}
                         });
    ib2.attachIndexData({0, 1, 2});
    object2.attachVertexBuffer(vb2);
    object2.attachIndexBuffer(ib2);
    object2.linkShader("simple");
    ren.registerObject(window, object2);


    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
