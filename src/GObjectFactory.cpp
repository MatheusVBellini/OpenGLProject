#include "../include/GObjectFactory.h"

GObjectFactory::STATE GObjectFactory::state = IDLE;
std::vector<uv> GObjectFactory::vertex_data;
std::vector<unsigned int> GObjectFactory::index_data;
std::string GObjectFactory::shader_name;

void GObjectFactory::errorMsg(const std::string& msg) {
    std::cout << "<GObjectFactory> " + msg << std::endl;
}

void GObjectFactory::initProduction() {
    if (state != IDLE) {
        errorMsg("Object already in production, could not start new one.");
        return;
    }
    state = VERTEX;
}

void GObjectFactory::setVertexBuffer(std::vector<uv>& data) {
    if (state != VERTEX) {
        errorMsg("Cannot define vertices, production must be initialized first. Try: initProduction().");
        return;
    }
    state = INDEX;
    vertex_data = data;
}

void GObjectFactory::setIndexBuffer(std::vector<unsigned int>& data) {
    if (state != INDEX) {
        errorMsg("Cannot define indexes, vertices must be set first. Try: setVertexBuffer().");
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
    state = IDLE;

    GObject object;
    VertexBuffer vb;
    VertexBuffer ib;

    vb.attachVertexData(vertex_data);
    ib.attachIndexData(index_data);
    object.attachVertexBuffer(vb);
    object.attachIndexBuffer(ib);
    object.linkShader(shader_name);

    return object;
}
