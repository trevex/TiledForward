#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "app.h"
#include "renderer.h"

void GLFWCALL resize(int, int);

CApp::CApp(void) : m_bRunning(true) {
	
}

CApp::~CApp(void) {
	// Close window and terminate GLFW
	glfwTerminate();
}

CApp& CApp::instance(void) {
	static std::unique_ptr<CApp> ptr(new CApp());
    return *ptr;
}

bool CApp::initialize(const char* title, int width, int height, bool fullscreen) {
	// Try to initialize OpenGL
	if (!glfwInit()) {
		std::cout << "Unable to initialize OpenGL!" << std::endl;
		return false;
	}
	// Setup GLFW Profile
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Try to open the window
	int mode = fullscreen ? GLFW_FULLSCREEN : GLFW_WINDOW;
	if (!glfwOpenWindow(width, height, 0, 0, 0, 0, 32, 0, mode))	{
		std::cout << "Unable to open window!" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwSetWindowTitle(title);
	// Try to initialize GLEW
	glewExperimental = GL_TRUE; 
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW!" << std::endl;
		return false;
	}
	// Enable sticky keys for capturing
	glfwEnable(GLFW_STICKY_KEYS);
	// Try to initialize the Renderer
	if (!Renderer.initialize()) {
		std::cout << "Unable to initialize Renderer!" << std::endl;
		glfwTerminate();
		return false;
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
	Renderer.render();
	return m_bRunning;
}

void GLFWCALL resize(int width, int height)
{
	if (height == 0) height=1;
	Renderer.resize((float)width, (float)height);
}