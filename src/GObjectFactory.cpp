#include "../include/GObjectFactory.h"
#include "../include/FileParser.h"

bool GObjectFactory::with_texture = false;

GObjectFactory::STATE GObjectFactory::state = IDLE;
std::vector<uv> GObjectFactory::vertex_data;
std::vector<unsigned int> GObjectFactory::index_data;
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
    state = VERTEX;
}

void GObjectFactory::setVertexBuffer(std::vector<uv>& data) {
    if (state != VERTEX) {
        errorMsg("Cannot define vertices, production must be initialized first. Try: initProduction().");
        return;
    }
    state = (with_texture) ? TEXTURE : INDEX;
    vertex_data = data;
}

void GObjectFactory::setIndexBuffer(std::vector<unsigned int>& data) {
    if (state != INDEX) {
        if (with_texture)
            errorMsg("Objects with texture don't support index buffers. Try: setTexture().");
        else
            errorMsg("Cannot define indexes, vertices must be set first. Try: setVertexBuffer().");
        return;
    }
    state = SHADER;
    index_data = data;
}

void GObjectFactory::setTexture(const std::string& filename, std::vector<uv_texture>& data) {
    if (state != TEXTURE) {
        if (with_texture)
            errorMsg("Cannot define texture, vertices must be set first. Try: setVertexBuffer().");
        else
            errorMsg("Object without texture specified. Try: setIndexBuffer().");
        return;
    }

    state = SHADER;
    texture_filename = filename;

    unsigned buffer;

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(uv_texture), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(uv_texture), (void*) 0);
    glEnableVertexAttribArray(1);
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

    vb.attachVertexData(vertex_data);
    object.attachVertexBuffer(vb);
    if (with_texture) {
        object.linkTexture(texture_filename);
    }
    else {
        ib.attachIndexData(index_data);
    }
    object.attachIndexBuffer(ib);
    object.linkShader(shader_name);

    state = IDLE;
    GObjectFactory::with_texture = false;
    return object;
}

GObject GObjectFactory::genObjectFromFile(const std::string &name) {
    FileParser fp;
    std::string filepath = "../data/objects/" + name + ".obj";

    fp.objParse(filepath);

    return GObject();
}




