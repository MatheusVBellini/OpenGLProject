#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

inline void CheckOpenGLError(const char* fname, int line) {
    GLenum err = glGetError();
    while (err != GL_NO_ERROR) {
        std::cerr << "OpenGL error " << err
                  << " - At " << fname << ":" << line << std::endl;
        err = glGetError();  // To retrieve all error flags until GL_NO_ERROR is returned.
    }
}

#define CHECK_GL_ERRORS() CheckOpenGLError(__FILE__, __LINE__)

inline void warnDebug(const char* fname, int line) {
    std::cout << "DEBUG: " << fname << ":" << line << std::endl;
}

inline void printvec3(const glm::vec3 vec) {
    std::cout << "( " << vec.x << " , " << vec.y << " , " << vec.z << " )" << std::endl;
}

#define DEBUG() warnDebug(__FILE__, __LINE__)