#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <map>
#include "GObject.h"

class Window {
private:
    GLFWwindow* window;

public:
    std::map<std::string,GObject*> objects;

    explicit Window(const int& width = 400,
           const int& height = 400,
           const std::string& title = "");
    ~Window();

    GLFWwindow* getWindowRef() const;
    int shouldClose() const;
    void attachObject(GObject& object);
    void detachObject(GObject& object);

};
