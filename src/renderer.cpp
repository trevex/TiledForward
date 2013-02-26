#include <memory>
#include <GL/glfw.h>

#include "renderer.h"

CRenderer::CRenderer(void) {

}

CRenderer::~CRenderer(void) {

}

CRenderer& CRenderer::instance(void) {
	static std::unique_ptr<CRenderer> ptr(new CRenderer());
    return *ptr;
}

bool CRenderer::initialize(void) {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 


	return true;
}

void CRenderer::resize(float width, float height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void CRenderer::render(void) {
	glfwSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

