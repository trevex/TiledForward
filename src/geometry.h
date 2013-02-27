#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

class CGeometry {
public:
	CGeometry(const std::vector<glm::vec3> &vertData, const std::vector<glm::vec2> &uvData, const std::vector<GLushort> &indexData, bool dynamic = false);
	~CGeometry(void);

	void bind(void);
	void draw(void);
	void unbind(void);
protected:
private:
	GLuint m_vertices;
	GLuint m_uvs;
	GLuint m_indices;
	GLuint m_indicesLength;
};

#endif