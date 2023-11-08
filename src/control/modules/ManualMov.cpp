#include "../../../include/control/modules/ManualMov.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

ManualMov::ManualMov() {
    v = 0.01;
    t = 0.05;

    defFuncs();

    // wasd movement
    key_func.emplace_back("a",moveLeft);
    key_func.emplace_back("d",moveRight);
    key_func.emplace_back("w",moveUp);
    key_func.emplace_back("s",moveDown);
    key_func.emplace_back("left_shift",moveAway);
    key_func.emplace_back("space",moveCloser);

    // rotation with arrows
    key_func.emplace_back("down_arrow",rotateXACW);
    key_func.emplace_back("up_arrow",rotateXCW);
    key_func.emplace_back("right_arrow",rotateYACW);
    key_func.emplace_back("left_arrow",rotateYCW);

    // scale
    key_func.emplace_back("z",shrink);
    key_func.emplace_back("x",grow);

}

ManualMov::~ManualMov() = default;

bool ManualMov::checkBoundaries(const glm::mat4& mat, const GObject* obj) {
    bool value = true;
    glm::vec4 boundary = {0,0,0,0};

    // translation validation
    for (auto& current : obj->getHitbox()) {
        boundary = mat * glm::vec4(current,1);
        if ((boundary.x > 1) || (boundary.x < -1)) value = false;
        if ((boundary.y > 1) || (boundary.y < -1)) value = false;
        if ((boundary.z > 1) || (boundary.z < -1)) value = false;
    }

    return value;
}

void ManualMov::defFuncs() {

    moveLeft = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(-v,0,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    moveRight = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(v,0,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    moveUp = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(0,v,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    moveDown = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(0,-v,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    moveAway = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(0,0,-v));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    moveCloser = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(0,0,v));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    rotateXACW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), t, glm::vec3(1,0,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    rotateXCW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), -t, glm::vec3(1,0,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    rotateYACW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), -t, glm::vec3(0,1,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    rotateYCW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), t, glm::vec3(0,1,0));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    grow = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::scale(object->getMovement(), glm::vec3(1.1,1.1,1.1));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

    shrink = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::scale(object->getMovement(), glm::vec3(0.9,0.9,0.9));
        if (checkBoundaries(mat,object))
            object->setMovement(mat);
    };

}


