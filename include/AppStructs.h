#pragma once

#include <glm/glm.hpp>

typedef struct {
    std::string material_name;
    std::string obj_name;
    std::vector<std::string> mtllibs;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normal_vertices;
    std::vector<glm::vec2> texture_vertices;
    bool smooth_shading;
    std::vector<unsigned> indexes;
} ObjFileInfo;