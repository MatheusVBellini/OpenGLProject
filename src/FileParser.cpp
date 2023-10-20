#include "../include/FileParser.h"

std::ifstream FileParser::readFile(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Unable to open: " << filepath << std::endl;
        exit(1);
    }

    return file;
}

std::vector<std::string> FileParser::split(const std::string &str, char delimiter) {
    std::vector<std::string> slices;
    std::string slice;
    std::istringstream stream(str);

    while (std::getline(stream, slice, delimiter)) {
        slices.push_back(slice);
    }

    return slices;

}

float FileParser::strToFloat(const std::string &str) {
    float num = 0;

    try {
        num = std::stof(str);
    } catch(std::invalid_argument& e) {
        std::cerr << "<FileParser> Failed to convert string to float.";
    } catch(std::out_of_range& e) {
        std::cerr << "<FileParse> String to float conversion is out-of-bounds.";
    }

    return num;

}

std::tuple<std::string, std::string> FileParser::glslParse(const std::string& filepath) {
    std::ifstream file = readFile(filepath);

    int vertex = 0;
    std::string vertex_shader;

    int fragment = 0;
    std::string fragment_shader;

    std::string line;
    std::string* stream = nullptr;
    while (std::getline(file,line)) {

        // select which shader is being read
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                vertex = 1;
                stream = &vertex_shader;
                continue;
            } else if (line.find("fragment") != std::string::npos) {
                fragment = 1;
                stream = &fragment_shader;
                continue;
            }
        }

        // store shader code
        *stream += line + "\n";
    }

    if (vertex + fragment != 2) {
        std::cerr << "Unable to parse shader: " << filepath << std::endl;
        exit(1);
    }

    return {vertex_shader, fragment_shader};

}

ObjFileInfo FileParser::objParse(const std::string &filepath) {
    std::ifstream file = readFile(filepath);
    std::string line;
    std::vector<std::string> split_line;

    // return variables
    std::string material_name;
    std::string obj_name;
    std::vector<std::string> mtllibs;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normal_vertices;
    std::vector<glm::vec2> texture_vertices;
    bool smooth_shading;
    std::vector<unsigned> indexes;

    // auxiliary variables
    glm::vec3 coord;
    glm::vec2 tex_coord;
    unsigned index;
    std::vector<std::string> split_indexes;

    while (std::getline(file, line)) {

        split_line = split(line, ' ');

        if (split_line.empty()) continue;

        if (split_line.at(0) == "mtllib") {  // material libraries

            split_line.erase(split_line.begin());
            mtllibs = split_line;

        } else if (split_line.at(0) == "o") {  // object name

            obj_name = split_line.at(1);

        } else if (split_line.at(0) == "v") {  // vertices

            coord.x = strToFloat(split_line.at(1));
            coord.y = strToFloat(split_line.at(2));
            coord.z = strToFloat(split_line.at(3));
            vertices.push_back(coord);

        } else if (split_line.at(0) == "vt") {  // texture vertices

            tex_coord.x = strToFloat(split_line.at(1));
            tex_coord.y = strToFloat(split_line.at(2));
            texture_vertices.push_back(tex_coord);

        } else if (split_line.at(0) == "vn") {  // normal vertices

            coord.x = strToFloat(split_line.at(1));
            coord.y = strToFloat(split_line.at(2));
            coord.z = strToFloat(split_line.at(3));
            normal_vertices.push_back(coord);

        } else if (split_line.at(0) == "usemtl") {  // material to be used

            material_name = split_line.at(1);

        } else if (split_line.at(0) == "s") {  // smooth shading

            if (split_line.at(1) == "on") smooth_shading = true;
            else if (split_line.at(1) == "off") smooth_shading = false;

        } else if (split_line.at(0) == "f") {  // face elements

            // v1
            split_indexes = split(split_line.at(1), '/');
            indexes.push_back((unsigned)strToFloat(split_indexes.at(0)));

            // v2
            split_indexes = split(split_line.at(2), '/');
            indexes.push_back((unsigned)strToFloat(split_indexes.at(0)));

            // v2
            split_indexes = split(split_line.at(3), '/');
            indexes.push_back((unsigned)strToFloat(split_indexes.at(0)));

        }

    }

    // return
    return {
        material_name,
        obj_name,
        mtllibs,
        vertices,
        normal_vertices,
        texture_vertices,
        smooth_shading,
        indexes
    };

}




