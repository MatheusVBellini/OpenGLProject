#shader vertex
#version 410 core

layout(location=0) in vec3 position;

void main() {
    gl_Position = vec4(position, 1.0);
}

#shader fragment
#version 410 core

out vec4 fragColor;

uniform vec4 color;
void main() {
    fragColor = color;
}