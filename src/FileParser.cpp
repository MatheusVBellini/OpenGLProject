#include <map>
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

std::pair<std::vector<ComposedCoord>,std::vector<unsigned>>
FileParser::composeCoordinates(const std::vector<std::array<std::array<unsigned int, 3>, 3>> &faces,
                               const std::vector<glm::vec3> &vertex_coords,
                               const std::vector<glm::vec2> &texture_coords,
                               const std::vector<glm::vec3> &normal_coords) {

    std::map<std::tuple<unsigned,unsigned,unsigned>, unsigned> loaded_indexes; // maps (vertex_index, texture_index, normal_index) -> (element_index)
    std::vector<ComposedCoord> composed_coords; // return vector
    ComposedCoord coord; // vector element
    std::vector<unsigned> indexes; // component order

    for (auto& face : faces) {
        for (auto& component : face) {
            unsigned vertex = component.at(0);
            unsigned texture = component.at(1);
            unsigned normal = component.at(2);

            // if component has not been loaded yet
            if (loaded_indexes.find({vertex,texture,normal}) == loaded_indexes.end()) {
                loaded_indexes[{vertex,texture,normal}] = composed_coords.size();
                coord.vertex_coord = vertex_coords.at(vertex);
                coord.texture_coord = texture_coords.at(texture);
                coord.normal_coord = normal_coords.at(normal);
                composed_coords.push_back(coord); // fill up composed coordinates
            }

            indexes.push_back(loaded_indexes[{vertex,texture,normal}]); // fill up indexes

        }
    }

    return std::make_pair(composed_coords,indexes);
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
    std::vector<glm::vec3> vertex_coords;
    std::vector<glm::vec2> texture_coords;
    std::vector<glm::vec3> normal_coords;
    bool smooth_shading;

    // auxiliary variables
    glm::vec3 coord;
    glm::vec2 texture_coord;
    std::vector<std::string> split_indexes;
    std::array<unsigned,3> face_indexes{};
    std::array<std::array<unsigned,3>,3> face{};
    std::vector<std::array<std::array<unsigned,3>,3>> faces;


    // data acquisition
    while (std::getline(file, line)) {

        split_line = split(line, ' ');

        if (split_line.empty()) continue;

        if (split_line.at(0) == "mtllib") {  // material libraries

            split_line.erase(split_line.begin());
            mtllibs = split_line;

        } else if (split_line.at(0) == "o") {  // object name

            obj_name = split_line.at(1);

        } else if (split_line.at(0) == "v") {  // vertex_coords

            coord.x = strToFloat(split_line.at(1));
            coord.y = strToFloat(split_line.at(2));
            coord.z = strToFloat(split_line.at(3));
            vertex_coords.push_back(coord);

        } else if (split_line.at(0) == "vt") {  // texture vertex_coords

            texture_coord.x = strToFloat(split_line.at(1));
            texture_coord.y = strToFloat(split_line.at(2));
            texture_coords.push_back(texture_coord);

        } else if (split_line.at(0) == "vn") {  // normal vertex_coords

            coord.x = strToFloat(split_line.at(1));
            coord.y = strToFloat(split_line.at(2));
            coord.z = strToFloat(split_line.at(3));
            normal_coords.push_back(coord);

        } else if (split_line.at(0) == "usemtl") {  // material to be used

            material_name = split_line.at(1);

        } else if (split_line.at(0) == "s") {  // smooth shading

            if (split_line.at(1) == "on") smooth_shading = true;
            else if (split_line.at(1) == "off") smooth_shading = false;

        } else if (split_line.at(0) == "f") {  // face elements

            // first set of coords
            split_indexes = split(split_line.at(1), '/');
            face_indexes.at(0) = (unsigned) strToFloat(split_indexes.at(0)) - 1;
            face_indexes.at(1) = (unsigned) strToFloat(split_indexes.at(1)) - 1;
            face_indexes.at(2) = (split_indexes.size() == 3) ? (unsigned) strToFloat(split_indexes.at(2)) - 1 : 0;
            face.at(0) = face_indexes;

            // second set of coords
            split_indexes = split(split_line.at(2), '/');
            face_indexes.at(0) = (unsigned) strToFloat(split_indexes.at(0)) - 1;
            face_indexes.at(1) = (unsigned) strToFloat(split_indexes.at(1)) - 1;
            face_indexes.at(2) = (split_indexes.size() == 3) ? (unsigned) strToFloat(split_indexes.at(2)) - 1 : 0;
            face.at(1) = face_indexes;

            // third set of coords
            split_indexes = split(split_line.at(3), '/');
            face_indexes.at(0) = (unsigned) strToFloat(split_indexes.at(0)) - 1;
            face_indexes.at(1) = (unsigned) strToFloat(split_indexes.at(1)) - 1;
            face_indexes.at(2) = (split_indexes.size() == 3) ? (unsigned) strToFloat(split_indexes.at(2)) - 1 : 0;
            face.at(2) = face_indexes;

            faces.push_back(face);

        }

    }

    // for .obj with no normals
    if (normal_coords.empty()) {
       glm::vec3 vn = {0,0,0};
       normal_coords.push_back(vn);
    }

    auto [composed_coords, indexes] = composeCoordinates(faces, vertex_coords, texture_coords, normal_coords);

    // return
    return {
            material_name,
            obj_name,
            mtllibs,
            vertex_coords,
            normal_coords,
            texture_coords,
            composed_coords,
            smooth_shading,
            indexes
    };

}






