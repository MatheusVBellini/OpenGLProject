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
    static glm::vec3 camera_position;
    static glm::vec3 camera_target;
    static glm::vec3 camera_up;

    static glm::mat4 view_mat;

    // Perspective Projection Matrix components
    static float fov;
    static float aspect_ratio;
    static float near_plane;
    static float far_plane;

    static glm::mat4 projection_mat;

    // Orthographic Projection Matrix components


public:
    static void initCamera(int wWidth = 800, int wHeight = 800); // static constructor

    static glm::mat4 getView(); // returns the View Matrix based on camera info
    static glm::mat4 getProjection(); // return the Projection Matrix

};

