#include <glm/gtc/matrix_transform.hpp>
#include "include/Application.h"
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
    GObject caixa = GObjectFactory::genObjectFromFile("caixa", "caixa2.jpg");
    GObject monstro = GObjectFactory::genObjectFromFile("monstro", "monstro.jpg");

    // controller instantiation
    Controller con;
    ManualMov module;
    con.loadModule(module);

    /* PROJECT FUNCTIONS */

    // show Nth object when key N is pressed
    std::array<GObject*,2> objects = {&caixa, &monstro};
    for (int i = 0; i < objects.size(); i++) {
        con.setKeyFunc(std::to_string(i+1), [&window, &con, &objects, i](int,int,int action,int,GObject* previous){
            if (!action) return;

            // remove previous object
            window.detachObject(*previous);
            con.detachObject();

            // attach object
            window.attachObject(*objects.at(i));
            con.attachObject(*objects.at(i));
        });
    }

    // toggle textures in current object
    con.setKeyFunc("p",[&ren](int,int,int action,int,GObject* object){
        if (!action) return;
        ren.fetchTexture(object->getTextureFilename()).toggle();
    });

    // toggle texture magnification algorithm
    bool linear = true;
    con.setKeyFunc("v",[&ren, &linear](int,int,int action,int,GObject* object){
        if (!action) return;
        Texture& tex = ren.fetchTexture(object->getTextureFilename());

        linear = !linear;

        tex.bind();
        (linear) ?
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR) :
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        tex.unbind();
    });

    /**********    ***********/

    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
