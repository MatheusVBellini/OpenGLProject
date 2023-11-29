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

    // Perspective Projection Matrix components


    // Orthographic Projection Matrix components


public:
    static glm::mat4 getView(); // returns the View Matrix based on camera info

};

