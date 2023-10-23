#shader vertex
#version 410 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texture_coord;
out vec2 out_texture;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 shiftBack;
uniform mat4 shiftForward;
uniform mat4 displacement;
uniform mat4 scale;
uniform mat4 rotationX;
uniform mat4 rotationY;
uniform mat4 rotationZ;

void main() {
    mat4 movement = displacement * shiftForward * rotationX * rotationY * rotationZ * shiftBack;
    mat4 modelMatrix = movement;
    gl_Position = modelMatrix * vec4(position, 1.0);
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
    fragColor = tex * color;
}