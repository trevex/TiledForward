#include <GL/glfw.h>
#include <stdlib.h>

void GLFWCALL resize(int width, int height)
{
	if (height == 0) height=1;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main( void )
{
	int running = GL_TRUE;
	
	// Initialize GLFW
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	
	// Open an OpenGL window
	if (!glfwOpenWindow(800, 600, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Setup OpenGL State Machine
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f); 
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	// Triangle rotation
	float triangle_rotation = 0.0f;
	glMatrixMode(GL_MODELVIEW);

	glfwSetWindowSizeCallback(resize);
	// Main loop
	while (running)
	{
		// OpenGL rendering goes here...
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Draw triangle
		glLoadIdentity();
		glPushMatrix();
		glTranslatef(0.0f,0.0f,-6.0f);
		glRotatef(triangle_rotation,0.0f,1.0f,0.0f);
		glBegin(GL_TRIANGLES);
			glColor3f(1.0f,0.0f,0.0f);
			glVertex3f( 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f,1.0f,0.0f);
			glVertex3f(-1.0f,-1.0f, 1.0f);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f( 1.0f,-1.0f, 1.0f);
			glColor3f(1.0f,0.0f,0.0f);
			glVertex3f( 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f( 1.0f,-1.0f, 1.0f);
			glColor3f(0.0f,1.0f,0.0f);
			glVertex3f( 1.0f,-1.0f, -1.0f);
			glColor3f(1.0f,0.0f,0.0f);
			glVertex3f( 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f,1.0f,0.0f);
			glVertex3f( 1.0f,-1.0f, -1.0f);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(-1.0f,-1.0f, -1.0f);
			glColor3f(1.0f,0.0f,0.0f);
			glVertex3f( 0.0f, 1.0f, 0.0f);
			glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(-1.0f,-1.0f,-1.0f);
			glColor3f(0.0f,1.0f,0.0f);
			glVertex3f(-1.0f,-1.0f, 1.0f);
		glEnd();
		glPopMatrix();
		// Swap front and back rendering buffers
		glfwSwapBuffers();
		// Rotate Triangle
		triangle_rotation += 0.2f;
		// Check if ESC key was pressed or window was closed
		running = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
	}
	// Close window and terminate GLFW
	glfwTerminate();
	// Exit program
	exit(EXIT_SUCCESS);
}