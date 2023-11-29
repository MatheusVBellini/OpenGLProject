#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Object responsible for dealing with the view and projection matrices
//
// Implemented statically for usage across function modules
//
class Camera {
private:

    // View Matrix components
    static glm::vec3 cameraPosition;
    static glm::vec3 cameraTarget;
    static glm::vec3 cameraUp;

    static glm::mat4 viewMat;

    // Perspective Projection Matrix components
    static float fov;
    static float aspectRatio;
    static float nearPlane;
    static float farPlane;

    static glm::mat4 projectionMat;

    // Orthographic Projection Matrix components


public:
    static void initCamera(int wWidth = 800, int wHeight = 800); // static constructor

    static glm::mat4 getView(); // returns the View Matrix based on camera info
    static glm::mat4 getProjection(); // return the Projection Matrix

};

