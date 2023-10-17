#shader vertex
#version 410 core

layout(location = 0) in vec3 position;
uniform mat4 shiftBack;
uniform mat4 shiftForward;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 displacement;
uniform mat4 scale;
uniform mat4 rotationX;
uniform mat4 rotationY;
uniform mat4 rotationZ;

void main() {
    mat4 movement = displacement * shiftForward * rotationX * rotationY * rotationZ * shiftBack;
    mat4 modelMatrix = movement;
    gl_Position = modelMatrix * vec4(position, 1.0);
}

#shader fragment
#version 410 core

uniform vec4 color;
void main() {
    gl_FragColor = color;
}