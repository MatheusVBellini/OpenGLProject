#shader vertex
#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coord;
out vec2 out_texture;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    mat4 mvp = view * model;
    gl_Position = mvp * vec4(position, 1.0);
    out_texture = vec2(texture_coord);
}

#shader fragment
#version 410 core

in vec2 out_texture;
uniform vec4 color;
uniform sampler2D samplerTexture;

out vec4 fragColor;

void main() {
    vec4 tex = texture(samplerTexture, out_texture);
    fragColor = tex;
}