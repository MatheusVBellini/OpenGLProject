#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
private:
    GLFWwindow* window;

public:
    explicit Window(const int& width = 400,
           const int& height = 400,
           const std::string& title = "");
    ~Window();

    GLFWwindow* getWindowRef() const;
    int shouldClose() const;
};
