#include <iostream>
#include <random>
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
#include "fbo.h"
#include "light.h"

#define LIGHT_NUMBER 100

int main( void )
{
	std::cout << "Starting Tile-based Forward Test Program by Niklas K. Voss (1004462)." << std::endl << std::endl;

	if (!App.initialize("Tile-based Forward")) {
		exit(EXIT_FAILURE);
	}
	if (!LightManager.initialize(128)) {
		exit(EXIT_FAILURE);
	}

	// RANDOM
	std::mt19937 gen;
	gen.seed(12);
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    // GENERATE LIGHTS
    std::vector<CLight> lights;
    lights.reserve(LIGHT_NUMBER);
    for (unsigned int i = 0; i < LIGHT_NUMBER; i++) {
    	lights.push_back(CLight(0.5f, glm::vec3(10.0f * dis(gen), 10.0f * dis(gen), 10.0f * dis(gen)), glm::vec3(dis(gen), dis(gen), dis(gen)), glm::vec3(-1.0f), glm::vec2(1.0f), glm::vec4(10 * dis(gen))));
    }

	// SHADER
	CShader geometryPass("shader/transform.vert", "shader/texture.frag");
	CShader lightPass("shader/light.vert", "shader/light.frag");

	CGeometry cube(*getCubeVertices(), *getCubeUVs(), *getCubeIndices());
	glm::mat4 cubeMatrix = glm::mat4(1.0f);

	CUniform mvp(geometryPass.getUniform("MVP"));
	CUniform diffuse(geometryPass.getUniform("diffuse"));
	CUniform offset(lightPass.getUniform("offset"));

	// LIGHTBUFFER
	CFBO lightBuffer(LightManager.getWidth(), LightManager.getHeight());
	lightPass.use();
	lightBuffer.bind();
	lightBuffer.clear();
	bool testSwitch = true;
	for (auto iter = lights.begin(); iter != lights.end(); iter++) {
		if (testSwitch) {
			offset.setFloat(iter->getOffset());
			LightManager.renderLightQuad();
		}
		testSwitch = !testSwitch;

	}
	lightBuffer.mipmap();
	lightBuffer.unbind();
	CTexture lightTex(lightBuffer.get());

	// LOOP
	while (App.run()) {
		geometryPass.use();
		mvp.setMatrix(Camera.getMVP(cubeMatrix));

		lightTex.bind(0);
		diffuse.setSamplerId(0);

		cube.bind();
		cube.draw();
		cube.unbind();	
		
	}

	exit(EXIT_SUCCESS);
}