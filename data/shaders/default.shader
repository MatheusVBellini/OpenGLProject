#shader vertex
#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coord;
layout(location = 2) in vec3 normals;

out vec2 out_texture;
out vec3 out_fragPos;
out vec3 out_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    mat4 mvp = projection * view * model;

    gl_Position = mvp * vec4(position, 1.0);
    out_texture = vec2(texture_coord);
    out_fragPos = vec3(position);
    out_normal = normals;
}

#shader fragment
#version 410 core

in vec2 out_texture;
in vec3 out_fragPos;
in vec3 out_normal;

uniform sampler2D samplerTexture;
uniform vec3 lightPos;
uniform float ka;
uniform float kd;

vec3 lightColor = vec3(1.0,1.0,1.0);

out vec4 fragColor;

void main() {
    vec3 ambient = ka * lightColor;

    vec3 norm = normalize(out_normal);
    vec3 lightDir = normalize(lightPos - out_fragPos);
    float diff = max(dot(norm,lightDir), 0.0);
    vec3 diffuse = kd * diff * lightColor;

    vec4 tex = texture(samplerTexture, out_texture);
    vec4 result = vec4((ambient + diffuse), 1.0) * tex;
    fragColor = result;
}