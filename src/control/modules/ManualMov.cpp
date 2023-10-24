#include "../../../include/control/modules/ManualMov.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

ManualMov::ManualMov() {
    v = 0.05;
    t = 0.05;

    defFuncs();

    // wasd movement
    key_func.emplace_back("a",moveLeft);
    key_func.emplace_back("d",moveRight);
    key_func.emplace_back("w",moveUp);
    key_func.emplace_back("s",moveDown);

    // rotation with arrows
    key_func.emplace_back("down_arrow",rotateXACW);
    key_func.emplace_back("up_arrow",rotateXCW);
    key_func.emplace_back("left_arrow",rotateYACW);
    key_func.emplace_back("right_arrow",rotateYCW);

}

ManualMov::~ManualMov() = default;

void ManualMov::defFuncs() {
    moveLeft = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(-v,0,0));
        object->setMovement(mat);
    };

    moveRight = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(v,0,0));
        object->setMovement(mat);
    };

    moveUp = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(0,v,0));
        object->setMovement(mat);
    };

    moveDown = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::translate(object->getMovement(), glm::vec3(0,-v,0));
        object->setMovement(mat);
    };

    rotateXACW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), -t, glm::vec3(1,0,0));
        object->setMovement(mat);
    };

    rotateXCW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), t, glm::vec3(1,0,0));
        object->setMovement(mat);
    };

    rotateYACW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), t, glm::vec3(0,1,0));
        object->setMovement(mat);
    };

    rotateYCW = [this](int key, int, int action, int, GObject* object) {
        if (!action) return;
        glm::mat4 mat = glm::rotate(object->getMovement(), -t, glm::vec3(0,1,0));
        object->setMovement(mat);
    };
}