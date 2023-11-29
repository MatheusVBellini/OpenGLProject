#include "../include/GObjectFactory.h"
#include "../include/FileParser.h"

bool GObjectFactory::with_texture = false;

GObjectFactory::STATE GObjectFactory::state = IDLE;
std::string GObjectFactory::name;
std::vector<glm::vec3> GObjectFactory::vertex_data;
std::vector<unsigned int> GObjectFactory::index_data;
std::vector<glm::vec3> GObjectFactory::normal_data;
std::vector<ComposedCoord> GObjectFactory::composed_data;
std::string GObjectFactory::texture_filename;
std::string GObjectFactory::shader_name;

void GObjectFactory::errorMsg(const std::string& msg) {
    std::cerr << "<GObjectFactory> " + msg << std::endl;
}

void GObjectFactory::initProduction(const std::string& name, bool with_texture) {
    if (state != IDLE) {
        errorMsg("Object already in production, could not start new one.");
        return;
    }

    GObjectFactory::with_texture = with_texture;
    GObjectFactory::name = name;

    state = (with_texture) ? COMPOSE : VERTEX;
}

void GObjectFactory::setComposedBuffer(std::vector<ComposedCoord> &data) {
    if (state != COMPOSE) {
        errorMsg("Cannot set data, production must be started first. Try: initProduction().");
        return;
    }

    state = TEXTURE;
    composed_data = data;

}

void GObjectFactory::setVertexBuffer(std::vector<glm::vec3>& data) {
    if (state != VERTEX) {
        errorMsg("Cannot define vertex_coords, production must be initialized first. Try: initProduction().");
        return;
    }
    state = INDEX;
    vertex_data = data;
}

void GObjectFactory::setTexture(const std::string& filename) {
    if (state != TEXTURE) {
        errorMsg("Cannot define texture, composed data must be set first. Try: setComposedBuffer().");
        return;
    }

    state = NORMAL;
    texture_filename = filename;

}

void GObjectFactory::setNormals(std::vector<glm::vec3> &data) {
    if (state != NORMAL) {
        errorMsg("Textures were not yet set. Try: setTexture().");
        return;
    }

    state = INDEX;
    normal_data = data;

}

void GObjectFactory::setIndexBuffer(std::vector<unsigned int>& data) {
    if (state != INDEX) {
        if (with_texture) {
            errorMsg("Cannot define indexes, normals must be set first. Try: setNormals().");
        }
        else {
            errorMsg("Cannot define indexes, vertex_coords must be set first. Try: setVertexBuffer().");
        }
        return;
    }

    state = SHADER;
    index_data = data;

}

void GObjectFactory::setShader(const std::string& shader_name) {
    if (state != SHADER) {
        errorMsg("Cannot define shader, indexes must be set first. Try: setIndexBuffer().");
        return;
    }
    state = FINISHED;
    GObjectFactory::shader_name = shader_name;
}

GObject GObjectFactory::getObject() {
    if (state != FINISHED) {
        errorMsg("Cannot return object. Shader must be set first. Try: setShader().");
        return GObject();
    }

    GObject object;
    VertexBuffer vb;
    VertexBuffer ib;

    // object building
    object.setName(name);
    vb.attachVertexData(composed_data); // define data to render
    object.attachVertexBuffer(vb);
    ib.attachIndexData(index_data); // define order of data render
    object.attachIndexBuffer(ib);
    if (with_texture) object.linkTexture(texture_filename);
    object.linkShader(shader_name);

    // boundaries
    std::array<float,6> boundaries = getBoundaries(vertex_data);
    object.setHitbox(genHitbox(boundaries));

    // restarting variables
    state = IDLE;
    name = "";
    with_texture = false;
    shader_name = "";
    texture_filename = "";
    vertex_data.clear();
    index_data.clear();
    composed_data.clear();

    return object;
}

GObject GObjectFactory::genObjectFromFile(const std::string& obj_name, const std::string& texture_name) {
    FileParser fp;
    std::string filepath = "../data/objects/" + obj_name + ".obj";
    ObjFileInfo info = fp.objParse(filepath);

    initProduction(obj_name, true);
    setComposedBuffer(info.composed_coords);
    setTexture(texture_name);
    setNormals(info.normal_coords);
    setIndexBuffer(info.indexes);
    setShader("default");

    // for boundary generation
    vertex_data = info.vertex_coords;

    return getObject();
}

std::array<float, 6> GObjectFactory::getBoundaries(const std::vector<glm::vec3> &coords) {
    float top = -1;
    float bottom = 1;
    float left = 1;
    float right = -1;
    float front = 1;
    float back = -1;

    for (auto& coord : coords) {
        top = (coord.y > top) ? coord.y : top;
        bottom = (coord.y < bottom) ? coord.y : bottom;
        left = (coord.x < left) ? coord.x : left;
        right = (coord.x > right) ? coord.x : right;
        front = (coord.z < front) ? coord.z : front;
        back = (coord.z > back) ? coord.z : back;
    }

    return {top,bottom,left,right,front,back};
}

std::array<glm::vec3, 8> GObjectFactory::genHitbox(const std::array<float, 6> &boundaries) {
    // l - left, r - right
    // u - up, d - down
    // b - back, f - front
    glm::vec3 luf, ruf, lub, rub,
              ldf, rdf, ldb, rdb;

    float top = boundaries.at(0);
    float bottom = boundaries.at(1);
    float left = boundaries.at(2);
    float right = boundaries.at(3);
    float front = boundaries.at(4);
    float back = boundaries.at(5);

    luf = {left, top, front};
    ruf = {right, top, front};
    lub = {left, top, back};
    rub = {right, top, back};
    ldf = {left, bottom, front};
    rdf = {right, bottom, front};
    ldb = {left, bottom, back};
    rdb = {right, bottom, back};

    return {luf, ruf, lub, rub, ldf, rdf, ldb, rdb};
}










