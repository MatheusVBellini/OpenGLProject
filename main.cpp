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

    // Renderer test
    Renderer ren;
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
    ren.registerObject(object);

    // teste
    while(!window.shouldClose()) {

        // scene preparation
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // drawing
        ren.draw(object);

        // swap front and back buffers
        glfwSwapBuffers(window.getWindowRef());

        // event handler
        glfwPollEvents();
    }

    //app.init();

    return 0;
}
