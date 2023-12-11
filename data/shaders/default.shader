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

vec3 lightColor = vec3(1.0,1.0,1.0);
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform float Ia;
uniform float Il;
uniform float ks;
uniform float ns;

out vec4 fragColor;

void main() {
    vec3 ambient = Ia * lightColor;

    vec3 norm = normalize(out_normal);
    vec3 lightDir = normalize(lightPos - out_fragPos);
    float diff = max(dot(norm,lightDir), 0.0);
    vec3 diffuse = Il * diff * lightColor;

    vec3 viewDir = normalize(viewPos - out_fragPos);
    vec3 reflectDir = normalize(reflect(-lightDir,norm));
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), ns);
    vec3 specular = ks * spec * lightColor;

    vec4 tex = texture(samplerTexture, out_texture);
    vec4 result = vec4((ambient + diffuse + specular), 1.0) * tex;
    fragColor = result;
}