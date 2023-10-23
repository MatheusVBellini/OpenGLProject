#include "../include/Application.h"
#include "../include/Controller.h"

void Application::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    for (auto& controller : Controller::controllers) {
        controller->keyCallback(key, scancode, action, mods);
    }
}

Application &Application::getInstance() {
    static Application instance;
    return instance;
}

Application::Application() {
    glfwInit();
    window = nullptr;
    renderer = nullptr;
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
    glfwSetKeyCallback(window->getWindowRef(),Application::keyCallback);
}

void Application::init() {

    while(!window->shouldClose()) {

        // scene preparation
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // drawing
        for (auto& object : window->objects) {
            renderer->draw(*object);
        }

        // swap front and back buffers
        glfwSwapBuffers(window->getWindowRef());

        // event handler
        glfwPollEvents();
    }

}

void Application::bindRenderer(Renderer& renderer) {
    this->renderer = &renderer;
}




