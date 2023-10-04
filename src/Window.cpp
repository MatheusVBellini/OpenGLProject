//
// Created by matheusvb on 04/10/23.
//

#include "../include/Window.h"

Window::Window(const int &width, const int &height, const std::string& title) {
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
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
