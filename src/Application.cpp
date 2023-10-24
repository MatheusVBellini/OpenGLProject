#include "../include/Application.h"
#include "../include/control/Controller.h"

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
}

void Application::init() {
    glfwSetKeyCallback(window->getWindowRef(), Controller::keyEventHandler);
    glfwSetMouseButtonCallback(window->getWindowRef(), Controller::mouseButtonEventHandler);
    glfwSetCursorPosCallback(window->getWindowRef(), Controller::mousePositionHandler);

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
        Controller::automaticEventHandler();
    }

}

void Application::bindRenderer(Renderer& renderer) {
    this->renderer = &renderer;
}




