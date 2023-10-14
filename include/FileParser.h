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

public:
    std::tuple<std::string, std::string> glslParse(const std::string& filepath);
    ObjFileInfo objParse(const std::string& filepath);
};

