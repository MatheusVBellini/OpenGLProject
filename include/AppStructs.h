#pragma once

#include <glm/glm.hpp>

typedef struct {
    glm::vec3 vertex_coord;
    glm::vec2 texture_coord;
} ComposedCoord;

typedef struct {
    std::string material_name;
    std::string obj_name;
    std::vector<std::string> mtllibs;
    std::vector<glm::vec3> vertex_coords;
    std::vector<glm::vec3> normal_coords;
    std::vector<glm::vec2> texture_coords;
    std::vector<ComposedCoord> composed_coords;
    bool smooth_shading;
    std::vector<unsigned> indexes;
} ObjFileInfo;