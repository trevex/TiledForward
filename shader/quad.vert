#version 330 core

layout(location = 0) in vec3 inPosition;

void main() {
    gl_Position.xyz = inPosition;
    gl_Position.w = 1.0;
}