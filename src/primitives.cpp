#include "primitives.h"


std::vector<glm::vec3> cubeVertices = {
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3( 1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3( 1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3( 1.0f,-1.0f,-1.0f),
		glm::vec3( 1.0f, 1.0f,-1.0f),
		glm::vec3( 1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3( 1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f,-1.0f, 1.0f),
		glm::vec3( 1.0f,-1.0f, 1.0f),
		glm::vec3( 1.0f, 1.0f, 1.0f),
		glm::vec3( 1.0f,-1.0f,-1.0f),
		glm::vec3( 1.0f, 1.0f,-1.0f),
		glm::vec3( 1.0f,-1.0f,-1.0f),
		glm::vec3( 1.0f, 1.0f, 1.0f),
		glm::vec3( 1.0f,-1.0f, 1.0f),
		glm::vec3( 1.0f, 1.0f, 1.0f),
		glm::vec3( 1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3( 1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f,-1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3( 1.0f, 1.0f, 1.0f),
		glm::vec3(-1.0f, 1.0f, 1.0f),
		glm::vec3( 1.0f,-1.0f, 1.0f)
};

std::vector<glm::vec2> cubeUVs = { 
		glm::vec2(0.000059f, 1.0f-0.000004f), 
		glm::vec2(0.000103f, 1.0f-0.336048f), 
		glm::vec2(0.335973f, 1.0f-0.335903f), 
		glm::vec2(1.000023f, 1.0f-0.000013f), 
		glm::vec2(0.667979f, 1.0f-0.335851f), 
		glm::vec2(0.999958f, 1.0f-0.336064f), 
		glm::vec2(0.667979f, 1.0f-0.335851f), 
		glm::vec2(0.336024f, 1.0f-0.671877f), 
		glm::vec2(0.667969f, 1.0f-0.671889f), 
		glm::vec2(1.000023f, 1.0f-0.000013f), 
		glm::vec2(0.668104f, 1.0f-0.000013f), 
		glm::vec2(0.667979f, 1.0f-0.335851f), 
		glm::vec2(0.000059f, 1.0f-0.000004f), 
		glm::vec2(0.335973f, 1.0f-0.335903f), 
		glm::vec2(0.336098f, 1.0f-0.000071f), 
		glm::vec2(0.667979f, 1.0f-0.335851f), 
		glm::vec2(0.335973f, 1.0f-0.335903f), 
		glm::vec2(0.336024f, 1.0f-0.671877f), 
		glm::vec2(1.000004f, 1.0f-0.671847f), 
		glm::vec2(0.999958f, 1.0f-0.336064f), 
		glm::vec2(0.667979f, 1.0f-0.335851f), 
		glm::vec2(0.668104f, 1.0f-0.000013f), 
		glm::vec2(0.335973f, 1.0f-0.335903f), 
		glm::vec2(0.667979f, 1.0f-0.335851f), 
		glm::vec2(0.335973f, 1.0f-0.335903f), 
		glm::vec2(0.668104f, 1.0f-0.000013f), 
		glm::vec2(0.336098f, 1.0f-0.000071f), 
		glm::vec2(0.000103f, 1.0f-0.336048f), 
		glm::vec2(0.000004f, 1.0f-0.671870f), 
		glm::vec2(0.336024f, 1.0f-0.671877f), 
		glm::vec2(0.000103f, 1.0f-0.336048f), 
		glm::vec2(0.336024f, 1.0f-0.671877f), 
		glm::vec2(0.335973f, 1.0f-0.335903f), 
		glm::vec2(0.667969f, 1.0f-0.671889f), 
		glm::vec2(1.000004f, 1.0f-0.671847f), 
		glm::vec2(0.667979f, 1.0f-0.335851f)
};

std::vector<GLushort> cubeIndices = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
};

std::vector<glm::vec3>* getCubeVertices(void) {
	return &cubeVertices;
}

std::vector<glm::vec2>* getCubeUVs(void) {
	return &cubeUVs;
}
std::vector<GLushort>* getCubeIndices(void) {
	return &cubeIndices;
}