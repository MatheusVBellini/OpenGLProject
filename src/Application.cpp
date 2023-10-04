#include "../include/Application.h"

Application &Application::getInstance() {
    static Application instance;
    return instance;
}

Application::Application() {
    glfwInit();
    window = nullptr;
}

Application::~Application() {
    glfwTerminate();
}

void Application::bindWindow(Window& window_to_bind) {
    window = &window_to_bind;
    glfwMakeContextCurrent(window->getWindowRef());
    glfwSwapInterval(1);
}

void Application::showWindow() {
    glfwShowWindow(window->getWindowRef());
}

void Application::init() {
    while(!window->shouldClose()) {

        // scene preparation
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // drawing

        // swap front and back buffers
        glfwSwapBuffers(window->getWindowRef());

        // event handler
        glfwPollEvents();
    }
}


