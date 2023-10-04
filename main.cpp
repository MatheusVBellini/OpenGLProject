#include <iostream>
#include "include/Application.h"
#include "include/Shader.h"

int main() {
    // boot-up
    Application app = Application::getInstance();
    Window window(800, 800, "Hello World");
    app.bindWindow(window);
    app.showWindow();

    // shader
    Shader shader;
    shader.compile("default");

    app.init();

    return 0;
}
