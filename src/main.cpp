#include <iostream>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "app.h"
#include "shader.h"
#include "camera.h"
#include "uniform.h"
#include "geometry.h"
#include "primitives.h"
#include "texture.h"

int main( void )
{
	std::cout << "Starting Procedural Methods Program by Niklas K. Voss (1004462)." << std::endl << std::endl;

	if (!App.initialize("Procedural Methods")) {
		exit(EXIT_FAILURE);
	}

	CShader shader("shader/transform.vert", "shader/texture.frag");

	CGeometry cube(*getCubeVertices(), *getCubeUVs(), *getCubeIndices());
	CTexture cube_texture("textures/numbers.tga");
	glm::mat4 cube_matrix = glm::mat4(1.0f);

	CUniform mvp(shader.getUniform("MVP"));
	CUniform diffuse(shader.getUniform("uDiffuse"));

	// Main loop
	while (App.run()) {
		shader.use();
		mvp.setMatrix(Camera.getMVP(cube_matrix));

		cube_texture.bind(0);
		diffuse.setSamplerId(0);

		cube.bind();
		cube.draw();
		cube.unbind();	
		
	}

	exit(EXIT_SUCCESS);
}