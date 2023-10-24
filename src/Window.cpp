//
// Created by matheusvb on 04/10/23.
//

#include "../include/Window.h"

Window::Window(const int &width, const int &height, const std::string& title) {
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Necessary for macOS
#endif

    window = glfwCreateWindow(width,
                              height,
                              title.c_str(),
                              nullptr,
                              nullptr);
}

Window::~Window() {
    glfwDestroyWindow(window);
}

GLFWwindow *Window::getWindowRef() const {
    return window;
}

int Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::attachObject(GObject& object) {
    this->objects.push_back(&object);
}

