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

    // show object1 when 1 is pressed
    con.setKeyFunc("1", [&window, &con, &caixa](int,int,int action,int,GObject* previous){
        if (!action) return;

        // remove previous object
        window.detachObject(*previous);
        con.detachObject();

        // attach caixa
        window.attachObject(caixa);
        con.attachObject(caixa);
    });

    // show object2 when 2 is pressed
    con.setKeyFunc("2", [&window, &con, &monstro](int,int,int action,int,GObject* previous){
        if (!action) return;

        // remove previous object
        window.detachObject(*previous);
        con.detachObject();

        // attach monstro
        window.attachObject(monstro);
        con.attachObject(monstro);
    });

    // toggle textures in current object
    con.setKeyFunc("p",[&ren](int,int,int action,int,GObject* object){
        if (!action) return;
        ren.fetchTexture(object->getTextureFilename()).toggle();
    });

    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
