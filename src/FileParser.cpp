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

float FileParser::strToFloat(const std::string &str, std::string data_type) {
    float num = 0;
    
    try {
        num = std::stof(str);
    } catch(std::invalid_argument& e) {
        std::cerr << "<FileParser> Failed to convert string to float of datatype: %s.\n" << data_type << std::endl;
    } catch(std::out_of_range& e) {
        std::cerr << "<FileParse> String to float conversion is out-of-bounds.\n";
    }

    return num;

}

std::vector<glm::vec3> FileParser::centralize(const std::vector<glm::vec3>& coords) {
    std::vector<glm::vec3> centralized;
    glm::vec3 centralized_coord;
    glm::vec3 center;
    double x, y, z = 0;

    // find gravitational center
    for (auto& coord : coords) {
        x += coord.x;
        y += coord.y;
        z += coord.z;
    }
    x /= (double)coords.size();
    y /= (double)coords.size();
    z /= (double)coords.size();
    center = {x,y,z};

    // centralize vertices
    for (auto& coord : coords) {
        centralized_coord = coord - center;
        centralized.push_back(centralized_coord);
    }

    return centralized;

}

std::vector<glm::vec3> FileParser::normalize(const std::vector<glm::vec3>& coords) {
    std::vector<glm::vec3> normalized;
    glm::vec3 normalized_coord;
    float max = 1;

    // search for biggest coordinate
    for (auto& coord : coords) {
        if (std::fabs(coord.x) > max) max = std::fabs(coord.x);
        if (std::fabs(coord.y) > max) max = std::fabs(coord.y);
        if (std::fabs(coord.z) > max) max = std::fabs(coord.z);
    }

    // normalize vector
    for (auto& coord : coords) {
        normalized_coord = coord / max;
        normalized.push_back(normalized_coord);
    }

    return normalized;

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

            coord.x = strToFloat(split_line.at(1), "v");
            coord.y = strToFloat(split_line.at(2), "v");
            coord.z = strToFloat(split_line.at(3), "v");
            vertex_coords.push_back(coord);

        } else if (split_line.at(0) == "vt") {  // texture vertex_coords

            texture_coord.x = strToFloat(split_line.at(1), "vt");
            texture_coord.y = strToFloat(split_line.at(2), "vt");
            texture_coords.push_back(texture_coord);

        } else if (split_line.at(0) == "vn") {  // normal vertex_coords

            coord.x = strToFloat(split_line.at(1), "vn");
            coord.y = strToFloat(split_line.at(2), "vn");
            coord.z = strToFloat(split_line.at(3), "vn");
            normal_coords.push_back(coord);

        } else if (split_line.at(0) == "usemtl") {  // material to be used

            material_name = split_line.at(1);

        } else if (split_line.at(0) == "s") {  // smooth shading

            if (split_line.at(1) == "on") smooth_shading = true;
            else if (split_line.at(1) == "off") smooth_shading = false;

        } else if (split_line.at(0) == "f") {  // face elements

            split_line.erase(split_line.begin());
            std::vector<std::array<std::array<unsigned int, 3>, 3>> triangles = splitPolygonFace(split_line);
            for (const auto& triangle : triangles) {
                faces.push_back(triangle);
            }
        }
    }

    // for .obj with no normals
    if (normal_coords.empty()) {
       glm::vec3 vn = {0,0,0};
       normal_coords.push_back(vn);
    }

    vertex_coords = centralize(vertex_coords); // centralize coordinates
    vertex_coords = normalize(vertex_coords); // normalize coordinates

    // create composed vector and index vector
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

std::vector<std::array<std::array<unsigned int, 3>, 3>> FileParser::splitPolygonFace(const std::vector<std::string>& faceTokens) {
    std::vector<std::array<std::array<unsigned int, 3>, 3>> triangles;

    if (faceTokens.size() < 3) {
        // Not enough vertices to create a face
        return triangles;
    }

    // Extract the first vertex
    std::vector<std::string> v0Tokens = split(faceTokens[0], '/');
    unsigned int v0 = (unsigned)strToFloat(v0Tokens[0], "f") - 1;
    unsigned int t0 = (v0Tokens.size() > 1) ? (unsigned)strToFloat(v0Tokens[1], "f") - 1 : 0;
    unsigned int n0 = (v0Tokens.size() > 2) ? (unsigned)strToFloat(v0Tokens[2], "f") - 1 : 0;

    for (size_t i = 1; i < faceTokens.size() - 1; i++) {
        // Extract the second vertex
        std::vector<std::string> v1Tokens = split(faceTokens[i], '/');
        unsigned int v1 = (unsigned)strToFloat(v1Tokens[0], "f") - 1;
        unsigned int t1 = (v1Tokens.size() > 1) ? (unsigned)strToFloat(v1Tokens[1], "f") - 1 : 0;
        unsigned int n1 = (v1Tokens.size() > 2) ? (unsigned)strToFloat(v1Tokens[2], "f") - 1 : 0;

        // Extract the third vertex
        std::vector<std::string> v2Tokens = split(faceTokens[i + 1], '/');
        unsigned int v2 = (unsigned)strToFloat(v2Tokens[0], "f") - 1;
        unsigned int t2 = (v2Tokens.size() > 1) ? (unsigned)strToFloat(v2Tokens[1], "f") - 1 : 0;
        unsigned int n2 = (v2Tokens.size() > 2) ? (unsigned)strToFloat(v2Tokens[2], "f") - 1 : 0;

        // Create a triangle
        std::array<std::array<unsigned int, 3>, 3> triangle = {{
            {v0, t0, n0},
            {v1, t1, n1},
            {v2, t2, n2}
        }};

        triangles.push_back(triangle);
    }
    return triangles;
}
