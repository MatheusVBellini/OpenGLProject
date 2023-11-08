#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include <sstream>
#include <array>
#include <regex>
#include "AppStructs.h"


class FileParser {
private:
    std::ifstream readFile(const std::string& filepath);
    std::vector<std::string> split(const std::string& str, char delimiter); // splits a string using a delimiter between substrings
    float strToFloat(const std::string &str, std::string data_type); // converts a string to a float when possible
    std::vector<glm::vec3> centralize(const std::vector<glm::vec3>& coords); // centralize vertices by simple gravitational center
    std::vector<glm::vec3> normalize(const std::vector<glm::vec3>& coords); // normalize the vec3 to be between 0 and 1

    std::pair<std::vector<ComposedCoord>,std::vector<unsigned>>
    composeCoordinates(const std::vector<std::array<std::array<unsigned int, 3>, 3>> &faces,
                               const std::vector<glm::vec3> &vertex_coords,
                               const std::vector<glm::vec2> &texture_coords,
                               const std::vector<glm::vec3> &normal_coords);
    std::vector<std::array<std::array<unsigned int, 3>, 3>> splitPolygonFace(const std::vector<std::string>& faceTokens);


public:
    std::tuple<std::string, std::string> glslParse(const std::string& filepath);
    ObjFileInfo objParse(const std::string& filepath); // returns a struct with all the useful information in a .obj file
};