#include "../include/Camera.h"

#define INITIAL_Z 0.5f

glm::vec3 Camera::cameraPosition = glm::vec3(0.0f, 0.0f, INITIAL_Z);
glm::vec3 Camera::cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 Camera::cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

glm::mat4 Camera::getView() {
    return glm::lookAt(cameraPosition,cameraTarget,cameraUp);
}
