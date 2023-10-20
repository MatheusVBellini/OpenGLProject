#include <iostream>
#include "include/Application.h"
#include "include/VertexBuffer.h"
#include "include/Renderer.h"
#include "include/Debug.h"
#include "include/GObjectFactory.h"

int main() {
    // boot-up
    Application app = Application::getInstance();
    Window window(800, 800, "Hello World");
    Renderer ren;
    app.bindRenderer(ren);
    app.bindWindow(window);
    app.showWindow();

    // shader and texture loading
    ren.compileShaders();
    ren.loadTextures();

    // drawing triangle 1
    std::vector<uv> vec = {
            {-0.5,-0.5, 0},
            {0, 0.5, 0},
            {0.5,-0.5, 0}
    };
    std::vector<unsigned> index = {0,1,2};

    GObjectFactory::initProduction(false);
    GObjectFactory::setVertexBuffer(vec);
    GObjectFactory::setIndexBuffer(index);
    GObjectFactory::setShader("simple");
    GObject object = GObjectFactory::getObject();

    // drawing triangle 2
    vec = {
            {-1,-1, 0},
            {-1, -0.25, 0},
            {-0.25,-0.25, 0}
    };
    index = {0,1,2};

    GObjectFactory::initProduction(false);
    GObjectFactory::setVertexBuffer(vec);
    GObjectFactory::setIndexBuffer(index);
    GObjectFactory::setShader("simple");
    object = GObjectFactory::getObject();

    // test - creating object from file
    object = GObjectFactory::genObjectFromFile("caixa", "caixa2.jpg");
    window.attachObject(object);

    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
