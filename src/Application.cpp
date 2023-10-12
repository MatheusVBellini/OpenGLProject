#include "../include/Application.h"
#include "../include/VertexBuffer.h"
#include "../include/GObject.h"

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
    // setup context
    window = &window_to_bind;
    glfwMakeContextCurrent(window->getWindowRef());
    glfwSwapInterval(1);

    // init glew
    if (glewInit() != GLEW_OK) {
        std::cerr << "ERROR:: GLEW could not be initialized" << std::endl;
        exit(1);
    }

    std::cout << "<Application> GLEW initialized successfully!" << std::endl;
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
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

        // swap front and back buffers
        glfwSwapBuffers(window->getWindowRef());

        // event handler
        glfwPollEvents();
    }

}


