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

    // Perspective Projection Matrix components
    static float fov;
    static float aspect_ratio;
    static float near_plane;
    static float far_plane;

    // Orthographic Projection Matrix components


public:
    static void initCamera(int wWidth = 800, int wHeight = 800); // static constructor

    static glm::vec3 getPosition(); // returns current position
    static glm::vec3 getTarget(); // returns current target
    static glm::vec3 getCameraUp(); // returns up reference
    static glm::mat4 getView(); // returns the View Matrix based on camera info
    static glm::mat4 getProjection(); // return the Projection Matrix

    static void updateTarget(const glm::vec3& target); // changes the target
    static void updatePosition(const glm::vec3& position); // changes the position

};

