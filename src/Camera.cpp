#include <iostream>
#include "../include/Camera.h"

#define INITIAL_Z 5.0f

// static variable initialization
glm::vec3 Camera::camera_position;
glm::vec3 Camera::camera_target;
glm::vec3 Camera::camera_up;
float Camera::fov;
float Camera::aspect_ratio;
float Camera::near_plane;
float Camera::far_plane;

void Camera::initCamera(int wWidth, int wHeight) {
    std::cout << "<Camera> Camera initialized successfully!" << std::endl;

    // View Matrix components
    camera_position = glm::vec3(0.0f, 0.0f, INITIAL_Z);
    camera_target = glm::vec3(0.0f, 0.0f, 0.0f);
    camera_up = glm::vec3(0.0f, 1.0f, 0.0f);

    // Perspective Projection Matrix components
    fov = glm::radians(45.0f);
    aspect_ratio = ((float)wWidth) / ((float)wHeight);
    near_plane = 0.5f;
    far_plane = 10000.0f;

}

glm::vec3 Camera::getTarget() {
    return camera_target;
}

glm::vec3 Camera::getPosition() {
    return camera_position;
}

glm::vec3 Camera::getCameraUp() {
    return camera_up;
}

glm::mat4 Camera::getView() {
    return glm::lookAt(camera_position, camera_position + camera_target, camera_up);
}

glm::mat4 Camera::getProjection() {
    return glm::perspective(fov, aspect_ratio, near_plane, far_plane);
}

void Camera::updateTarget(const glm::vec3& target) {
    camera_target = target;
}

void Camera::updatePosition(const glm::vec3& position) {
    camera_position = position;
}








