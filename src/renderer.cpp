#include <memory>
#include <GL/glew.h>

#include "renderer.h"
#include "camera.h"

CRenderer::CRenderer(void) : m_vertArray(0) {

}

CRenderer::~CRenderer(void) {
	if (m_vertArray != 0) glDeleteVertexArrays(1, &m_vertArray);
}

CRenderer& CRenderer::instance(void) {
	static std::unique_ptr<CRenderer> ptr(new CRenderer());
    return *ptr;
}

bool CRenderer::initialize(void) {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 

	glGenVertexArrays(1, &m_vertArray);
	glBindVertexArray(m_vertArray);

	return true;
}

void CRenderer::resize(float width, float height) {
	Camera.setAspect(width / height);
}

void CRenderer::render(void) {
	glfwSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

