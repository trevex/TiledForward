#include <GL/glfw.h>

#include "app.h"

int main( void )
{
	App.initialize("Procedural Methods");
		
	// Triangle rotation
	float triangle_rotation = 0.0f;
	
	// Main loop
	while (App.run())
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
	}
}