#pragma once

typedef struct { float x,y,z; } uv;
typedef struct { float x,y; }   uv_texture;
typedef struct {
    std::string material_name;
    std::string obj_name;
    std::vector<std::string> mtllibs;
    std::vector<uv> vertices;
    std::vector<uv> normal_vertices;
    std::vector<uv_texture> texture_vertices;
    bool smooth_shading;
} ObjFileInfo;