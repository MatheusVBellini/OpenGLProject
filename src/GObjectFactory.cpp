#include "../include/GObjectFactory.h"
#include "../include/FileParser.h"

bool GObjectFactory::with_texture = false;

GObjectFactory::STATE GObjectFactory::state = IDLE;
std::vector<glm::vec3> GObjectFactory::vertex_data;
std::vector<unsigned int> GObjectFactory::index_data;
std::vector<ComposedCoord> GObjectFactory::composed_data;
std::string GObjectFactory::texture_filename;
std::string GObjectFactory::shader_name;

void GObjectFactory::errorMsg(const std::string& msg) {
    std::cerr << "<GObjectFactory> " + msg << std::endl;
}

void GObjectFactory::initProduction(bool with_texture) {
    if (state != IDLE) {
        errorMsg("Object already in production, could not start new one.");
        return;
    }

    GObjectFactory::with_texture = with_texture;
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

    object.setPivot(composed_data.at(0).vertex_coord);
    vb.attachVertexData(composed_data);
    object.attachVertexBuffer(vb);
    ib.attachIndexData(index_data);
    object.attachIndexBuffer(ib);
    if (with_texture) object.linkTexture(texture_filename);
    object.linkShader(shader_name);

    // restarting variables
    state = IDLE;
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

    initProduction(true);
    setComposedBuffer(info.composed_coords);
    setTexture(texture_name);
    setNormals(info.normal_coords);
    setIndexBuffer(info.indexes);
    setShader("default");

    return getObject();
}










