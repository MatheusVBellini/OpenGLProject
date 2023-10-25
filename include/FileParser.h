#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <sstream>
#include "AppStructs.h"

class FileParser {
private:
    std::ifstream readFile(const std::string& filepath);
    std::vector<std::string> split(const std::string& str, char delimiter);
    float strToFloat(const std::string& str);


    std::pair<std::vector<ComposedCoord>,std::vector<unsigned>> composeCoordinates(
            const std::vector<std::array<std::array<unsigned,3>,3>>& faces,
            const std::vector<glm::vec3>& vertex_coords,
            const std::vector<glm::vec2>& texture_coords,
            const std::vector<glm::vec3>& normal_coords
            );

public:
    std::tuple<std::string, std::string> glslParse(const std::string& filepath);
    ObjFileInfo objParse(const std::string& filepath);
};

