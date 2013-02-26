#include <iostream>
#include <stdlib.h>
#include <GL/glew.h>

#include "app.h"
#include "shader.h"

int main( void )
{
	std::cout << "Starting Procedural Methods Program by Niklas K. Voss (1004462)." << std::endl << std::endl;

	if (!App.initialize("Procedural Methods")) {
		exit(EXIT_FAILURE);
	}
	
	CShader shader("shader/simple.vert", "shader/simple.frag");

	GLuint vertArray;
	glGenVertexArrays(1, &vertArray);
	glBindVertexArray(vertArray);

	static const GLfloat vertexBufferData[] = { 
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

	GLuint vertBuffer;
	glGenBuffers(1, &vertBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	// Main loop
	while (App.run()) {
		shader.use();

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);
	}

	glDeleteBuffers(1, &vertBuffer);
	glDeleteVertexArrays(1, &vertArray);

	exit(EXIT_SUCCESS);
}