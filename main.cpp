#include <glm/gtc/matrix_transform.hpp>
#include "include/Application.h"
#include "include/Renderer.h"
#include "include/Debug.h"
#include "include/GObjectFactory.h"
#include "include/control/Controller.h"
#include "include/Camera.h"
#include "include/control/modules/CameraMov.h"
#include "include/Lamp.h"
#include "include/control/modules/LampControl.h"

// Global Variables
std::string windowTitle = "Trabalho 2";
int windowHeight = 1600;
int windowWidth = 1600;

int main() {
    // boot-up
    Application app = Application::getInstance();
    Window window(windowWidth, windowHeight, windowTitle);
    Renderer ren;
    app.bindRenderer(ren);
    app.bindWindow(window);
    app.showWindow();
    Camera::initCamera(windowWidth,windowHeight);

    // shader and texture loading
    ren.compileShaders();
    ren.loadTextures();

    // creating object from file
    GObject skull = GObjectFactory::genObjectFromFile("skull", "skull.jpg");
    GObject penguin = GObjectFactory::genObjectFromFile("penguin", "penguin.png");
    GObject head = GObjectFactory::genObjectFromFile("head", "head.jpg");
    GObject steve = GObjectFactory::genObjectFromFile("Steve", "Steve.jpg");
    GObject elephant = GObjectFactory::genObjectFromFile("elephant", "elephant.png");
    GObject skybox = GObjectFactory::genObjectFromFile("skybox", "skybox.png");

    // light source instantiation
    Lamp lamp;
    lamp.setCoeff({1.0,1.0});
    ren.attachLamp(lamp);

    // object reflection configuration
    elephant.setIllumination({0,1,10}); // specular-only

    // controller instantiation
    Controller con;

    // controller modules instantiation
    CameraMov camModule;
    LampControl lampModule(&lamp);
    con.loadModule(camModule);
    con.loadModule(lampModule);

    // skybox configuration
    window.attachObject(skybox);
    float skybox_scale = 100;
    glm::mat4 skybox_model = glm::scale(skybox.getMovement(),glm::vec3(skybox_scale)); // scale the skybox
    skybox_model = glm::translate(skybox_model, {0,0,0.5}); // center skybox on camera's spawn position
    skybox.setMovement(skybox_model);

    /* PROJECT FUNCTIONS */

    // show Nth object when key N is pressed
    std::array<GObject*,5> objects = {&skull, &penguin, &head, &steve, &elephant};
    for (int i = 0; i < objects.size(); i++) {
        con.setKeyFunc(std::to_string(i+1), [&window, &con, &objects, i](KEY_ARGS){
            if (!action) return;

            // remove object object
            window.detachObject(*object);
            con.detachObject();

            // attach object
            window.attachObject(*objects.at(i));
            con.attachObject(*objects.at(i));
        });
    }

    // toggle textures in current object
    con.setKeyFunc("p",[&ren](KEY_ARGS){
        if (!action) return;
        ren.fetchTexture(object->getTextureFilename()).toggle();
    });

    // toggle texture magnification algorithm
    bool linear = true;
    con.setKeyFunc("v",[&ren, &linear](KEY_ARGS){
        if (!action) return;
        Texture& tex = ren.fetchTexture(object->getTextureFilename());

        linear = !linear;

        tex.bind();
        (linear) ?
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR) :
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        tex.unbind();
    });

    // toggle mouse in the window
    auto windowref = window.getWindowRef();
    bool cursor = true;
    con.setMouseButtonFunc("right", [&windowref, &cursor](MOUSE_BUTTON_ARGS) {
        if (!action) return;

        if (cursor) glfwSetInputMode(windowref, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        else glfwSetInputMode(windowref, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        cursor = !cursor;
    });

    /**********    ***********/

    // main loop
    app.init();

    CHECK_GL_ERRORS();

    return 0;
}
