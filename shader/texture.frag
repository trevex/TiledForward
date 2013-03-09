#version 330 core

in vec2 UV;

out vec3 color;

uniform sampler2D diffuse;

void main(){
	color = texture2D(diffuse, UV).rgb;
}