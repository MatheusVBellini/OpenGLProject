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
    GObject object;
    VertexBuffer vb;
    vb.attachVertexData({
        {-0.5,-0.5, 0},
        {0, 0.5, 0},
        {0.5,-0.5, 0}
    });
    VertexBuffer ib;
    ib.attachIndexData({0, 1, 2});
    shader.bindBuffers();
    //object.attachVertexBuffer(vb);
    //object.attachIndexBuffer(ib);
    //object.linkShader("simple");
    //ren.registerObject(object);
    //object.linkShader("default");
    //ren.registerObject(object);

    shader.bind();
    vb.bind();
    ib.bind();
    shader.setUniform4f("color", {1,0,1,1});


    // teste
    while(!window.shouldClose()) {

        // scene preparation
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // drawing
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

        // swap front and back buffers
        glfwSwapBuffers(window.getWindowRef());

        // event handler
        glfwPollEvents();
    }

    //app.init();

    return 0;
}
