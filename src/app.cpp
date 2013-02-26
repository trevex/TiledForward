#include <iostream>
#include <memory>
#include <stdlib.h>
#include <GL/glfw.h>

#include "app.h"
#include "renderer.h"

void GLFWCALL resize(int, int);

CApp::CApp(void) : m_bRunning(true) {
	
}

CApp::~CApp(void) {
	// Close window and terminate GLFW
	glfwTerminate();
	// Exit program
	exit(EXIT_SUCCESS);
}

CApp& CApp::instance(void) {
	static std::unique_ptr<CApp> ptr(new CApp());
    return *ptr;
}

bool CApp::initialize(std::string title, int width, int height, bool fullscreen) {
	// Try to initialize OpenGL
	if (!glfwInit()) {
		std::cout << "Unable to initialize OpenGL!" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	// Try to open the window
	int mode = fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW;
	if (!glfwOpenWindow(width, height, 0, 0, 0, 0, 0, 0, mode))	{
		std::cout << "Unable to open window!" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetWindowTitle(title.c_str());

	// Try to initialize the Renderer
	if (!Renderer.initialize()) {
		std::cout << "Unable to initialize Renderer!" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Callbacks
	glfwSetWindowSizeCallback(resize);

	return true;
}

bool CApp::isRunning(void) const {
	return m_bRunning;
}

bool CApp::run(void) {
	// Check if ESC key was pressed or window was closed
	m_bRunning = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
	return m_bRunning;
}

void GLFWCALL resize(int width, int height)
{
	if (height == 0) height=1;
	glViewport(0, 0, width, height);
	Renderer.resize((float)width, (float)height);
}