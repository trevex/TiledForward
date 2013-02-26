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
	// Initialize OpenGL state machine
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f); 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glMatrixMode(GL_MODELVIEW);


	return true;
}

void CRenderer::resize(float width, float height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

