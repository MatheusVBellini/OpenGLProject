#shader vertex

attribute vec3 position;
attribute vec2 texture_coord;
varying vec2 out_texture;

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

uniform vec4 color;
varying vec2 out_texture;
uniform sampler2D samplerTexture;

void main() {
    vec4 texture = texture2D(samplerTexture, out_texture);
    gl_FragColor = color;
}