#include <iostream>
#include "include/Application.h"

int main() {
    Application app = Application::getInstance();
    Window window(800, 800, "Hello World");

    app.bindWindow(window);
    app.showWindow();
    app.init();

    return 0;
}
