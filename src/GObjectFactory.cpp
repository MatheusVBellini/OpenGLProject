#include "../include/GObjectFactory.h"
#include "../include/FileParser.h"
#include "../include/Debug.h"
#include "../include/AppConstants.h"

bool GObjectFactory::with_texture = false;

GObjectFactory::STATE GObjectFactory::state = IDLE;
std::vector<glm::vec3> GObjectFactory::vertex_data;
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

void GObjectFactory::setVertexBuffer(std::vector<glm::vec3>& data) {
    if (state != VERTEX) {
        errorMsg("Cannot define vertices, production must be initialized first. Try: initProduction().");
        return;
    }
    state = (with_texture) ? TEXTURE : INDEX;
    vertex_data = data;
}

void GObjectFactory::setTexture(const std::string& filename, std::vector<glm::vec2>& data) {
    if (state != TEXTURE) {
        if (with_texture)
            errorMsg("Cannot define texture, vertices must be set first. Try: setVertexBuffer().");
        else
            errorMsg("Object without texture specified. Try: setIndexBuffer().");
        return;
    }

    state = NORMAL;
    texture_filename = filename;

    unsigned buffer;

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(TEXTURE_SLOT, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*) 0);
    glEnableVertexAttribArray(1);
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
            errorMsg("Cannot define indexes, vertices must be set first. Try: setVertexBuffer().");
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
    Texture texture;

    vb.attachVertexData(vertex_data);
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

    return object;
}

GObject GObjectFactory::genObjectFromFile(const std::string& obj_name, const std::string& texture_name) {
    FileParser fp;
    std::string filepath = "../data/objects/" + obj_name + ".obj";
    ObjFileInfo info = fp.objParse(filepath);

    initProduction(true);
    setVertexBuffer(info.vertices);
    setTexture(texture_name, info.texture_vertices);
    setNormals(info.normal_vertices);
    setIndexBuffer(info.indexes);
    setShader("simple_with_texture");

    return getObject();
}






