#ifndef _QUAD_H_
#define _QUAD_H_

#include <memory>
#include <GL/glew.h>

static const GLfloat gQuadData[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    1.0f,  1.0f, 0.0f,
};

#define Quad CQuad::instance()

class CQuad {
public:
	CQuad() {
		glGenVertexArrays(1, &m_array);
		glBindVertexArray(m_array);
		glGenBuffers(1, &m_array);
		glBindBuffer(GL_ARRAY_BUFFER, m_array);
		glBufferData(GL_ARRAY_BUFFER, sizeof(gQuadData), gQuadData, GL_STATIC_DRAW);
	}
	~CQuad() {
		glDeleteBuffers(1, &m_array);
	}
	static CQuad& instance(void) {
		static std::unique_ptr<CQuad> ptr(new CQuad());
    	return *ptr;
	}
	void render(void) {
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, m_array);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glDisableVertexAttribArray(0);
	}
private:
	GLuint m_array;
};

#endif