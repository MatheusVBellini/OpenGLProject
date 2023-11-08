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
    Window window(800, 800, "Computer Graphics - Project");
    Renderer ren;
    app.bindRenderer(ren);
    app.bindWindow(window);
    app.showWindow();

    // shader and texture loading
    ren.compileShaders();
    ren.loadTextures();

    // creating object from file
    GObject skull = GObjectFactory::genObjectFromFile("skull", "skull.jpg");
    GObject penguin = GObjectFactory::genObjectFromFile("penguin", "penguin.png");
    GObject head = GObjectFactory::genObjectFromFile("head", "head.jpg");
    GObject hand = GObjectFactory::genObjectFromFile("hand", "hand.png");
    GObject elephant = GObjectFactory::genObjectFromFile("elephant", "elephant.png");

    std::cout << "\nMONSTRO" << std::endl;
    std::cout << "\ntop/bottom: " << monstro.top << "/" << monstro.bottom <<
    "\nleft/right: " << monstro.left << "/" << monstro.right <<
    "\nfront/back: " << monstro.front << "/" << monstro.back << std::endl;

    // controller instantiation
    Controller con;
    ManualMov module;
    con.loadModule(module);

    /* PROJECT FUNCTIONS */

    // show Nth object when key N is pressed
    std::array<GObject*,5> objects = {&skull, &penguin, &head, &hand, &elephant};
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
