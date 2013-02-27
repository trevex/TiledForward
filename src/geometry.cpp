#include <iostream>

#include "geometry.h"


CGeometry::CGeometry(const std::vector<glm::vec3> &vertData, const std::vector<glm::vec2> &uvData, const std::vector<GLushort> &indexData, bool dynamic) : m_vertices(0), m_uvs(0), m_indices(0), m_indicesLength(0) {
	GLenum mode = (dynamic) ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

	glGenBuffers(1, &m_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertices);
	glBufferData(GL_ARRAY_BUFFER, vertData.size() * sizeof(glm::vec3), &vertData[0], mode);

	glGenBuffers(1, &m_uvs);
	glBindBuffer(GL_ARRAY_BUFFER, m_uvs);	
	glBufferData(GL_ARRAY_BUFFER, uvData.size() * sizeof(glm::vec2), &uvData[0], mode);

	glGenBuffers(1, &m_indices);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indices);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexData.size() * sizeof(GLushort), &indexData[0], mode);
	
	m_indicesLength = indexData.size();

	std::cout << "Created geometry with Vertices: " << vertData.size() << ", UVs: " << uvData.size() << ", Indices: " << m_indicesLength << std::endl; 
}

CGeometry::~CGeometry(void) {
	glDeleteBuffers(1, &m_vertices);
	glDeleteBuffers(1, &m_uvs);
	glDeleteBuffers(1, &m_indices);
}

void CGeometry::bind(void) {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertices);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // attr, size, type, normalized, stride, offset
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_uvs);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0); // attr, size, type, normalized, stride, offset
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indices);
}

void CGeometry::draw(void) {
	glDrawElements(GL_TRIANGLES, m_indicesLength, GL_UNSIGNED_SHORT, 0);
}

void CGeometry::unbind(void) {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}