#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include "include/Application.h"
#include "include/VertexBuffer.h"
#include "include/Renderer.h"
#include "include/Debug.h"
#include "include/GObjectFactory.h"
#include "include/control/Controller.h"
#include "include/control/modules/ManualMov.h"


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

    // creating object from file
    GObject object = GObjectFactory::genObjectFromFile("caixa", "caixa2.jpg");
    window.attachObject(object);

    // test - controller
    Controller con;
    con.bindObject(object);

    // test - FuncModule;
    ManualMov module;
    con.loadModule(module);

    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
