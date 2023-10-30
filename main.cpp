#include <glm/gtc/matrix_transform.hpp>
#include "include/Application.h"
#include "include/Renderer.h"
#include "include/Debug.h"
#include "include/GObjectFactory.h"
#include "include/control/Controller.h"
#include "include/control/modules/ManualMov.h"
#include "include/AppConstants.h"


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
    GObject caixa = GObjectFactory::genObjectFromFile("caixa", "caixa2.jpg");
    GObject monstro = GObjectFactory::genObjectFromFile("monstro", "monstro.jpg");

    // controller instantiation
    Controller con;
    ManualMov module;
    con.loadModule(module);

    // project specifications
    con.setKeyFunc("1", [&window, &con, &caixa](int,int,int,int,GObject* previous){
        if (!previous) {
            window.detachObject(*previous);
            con.detachObject();
        }

        window.attachObject(caixa);
        con.attachObject(caixa);
    });

    con.setKeyFunc("2", [&window, &con, &monstro](int,int,int,int,GObject* previous){
        if (!previous) {
            window.detachObject(*previous);
            con.detachObject();
        }

        window.attachObject(monstro);
        con.attachObject(monstro);
    });

    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
