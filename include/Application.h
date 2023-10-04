#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"

class Application {
private:
    Window* window;

    explicit Application();

public:
    ~Application();

    static Application& getInstance();
    void bindWindow(Window& window);
    void showWindow();
    void init();
};
