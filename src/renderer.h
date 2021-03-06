#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GL/glfw.h>

#define Renderer CRenderer::instance()

class CRenderer {
public:
	CRenderer(void);
	~CRenderer(void);

	static CRenderer& instance(void);

	bool initialize(void);
	void resize(float width, float height);
	void render(void);
	void resetViewport(void);
protected:
private:
	GLuint m_vertArray;

	GLsizei m_width;
	GLsizei m_height;
};

#endif