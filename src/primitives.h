#ifndef _PRIMITIVES_H_
#define _PRIMITIVES_H_

#include <vector>
#include <GL/glfw.h>
#include <glm/glm.hpp>

std::vector<glm::vec3>* getCubeVertices(void);
std::vector<glm::vec2>* getCubeUVs(void);
std::vector<GLushort>* getCubeIndices(void);

#endif