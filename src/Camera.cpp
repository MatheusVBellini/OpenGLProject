#include <iostream>
#include "../include/Camera.h"

#define INITIAL_Z 0.5f

// static variable initialization
glm::vec3 Camera::cameraPosition;
glm::vec3 Camera::cameraTarget;
glm::vec3 Camera::cameraUp;
float Camera::fov;
float Camera::aspectRatio;
float Camera::nearPlane;
float Camera::farPlane;

void Camera::initCamera(int wWidth, int wHeight) {
    std::cout << "<Camera> Camera initialized successfully!" << std::endl;

    // View Matrix components
    cameraPosition = glm::vec3(0.0f, 0.0f, INITIAL_Z);
    cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    // Perspective Projection Matrix components
    fov = glm::radians(45.0f);
    aspectRatio = ((float)wWidth)/((float)wHeight);
    nearPlane = 0.1f;
    farPlane = 1.0f;

}

glm::mat4 Camera::getView() {
    return glm::lookAt(cameraPosition,cameraTarget,cameraUp);
}

glm::mat4 Camera::getProjection() {
    return glm::perspective(fov,aspectRatio,nearPlane,farPlane);
}


