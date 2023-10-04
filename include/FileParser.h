#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

class FileParser {
private:
    std::ifstream readFile(const std::string& filepath);

public:
    std::tuple<std::string, std::string> glslParse(const std::string& filepath);
};

