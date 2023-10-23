#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"
#include "Renderer.h"

class Application {
private:
    Window* window;
    Renderer* renderer;

    explicit Application();

    // events
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
    ~Application();

    static Application& getInstance();
    void bindWindow(Window& window);
    void showWindow();
    void bindRenderer(Renderer& renderer);
    void init();
};
