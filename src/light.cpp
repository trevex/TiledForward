#include <memory>
#include <vector>

#include "light.h"

#define LIGHT_ATTRIBUTES_SIZE 16

static const GLfloat gFullscreenQuadData[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    1.0f,  1.0f, 0.0f,
};

CLightManager::CLightManager(void) : m_maxLights(128), m_currentId(0), m_vertexArray(0) {

}

CLightManager::~CLightManager(void) {
	glDeleteBuffers(1, &m_vertexArray);
}
	
CLightManager& CLightManager::instance(void) {
	static std::unique_ptr<CLightManager> ptr(new CLightManager());
    return *ptr;
}

bool CLightManager::initialize(unsigned int maxLights) {
	m_maxLights = maxLights;
	float x = -((float)m_maxLights/2-1)/((float)m_maxLights/2);
	std::vector<glm::vec3> lightQuadData = {
		glm::vec3(-1.0f, -1.0f, 0.0f),
		glm::vec3(    x, -1.0f, 0.0f),
		glm::vec3(-1.0f,  1.0f, 0.0f),
		glm::vec3(-1.0f,  1.0f, 0.0f),
		glm::vec3(    x, -1.0f, 0.0f),
		glm::vec3(    x,  1.0f, 0.0f)
	};	
	glGenVertexArrays(1, &m_vertexArray);
	glBindVertexArray(m_vertexArray);
	glGenBuffers(1, &m_vertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArray);
	glBufferData(GL_ARRAY_BUFFER, lightQuadData.size() * sizeof(glm::vec3), &lightQuadData[0], GL_STATIC_DRAW);
	return true;
}

unsigned int CLightManager::getNextId(void) {
	return m_currentId++;
}

unsigned int CLightManager::getWidth(void) const {
	return m_maxLights;
}

unsigned int CLightManager::getHeight(void) const {
	return LIGHT_ATTRIBUTES_SIZE;
}

void CLightManager::renderLightQuad(void) {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArray);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
}



CLight::CLight(void) : m_type(0.0f), m_pos(1.0f), m_color(0.0f), m_dir(-1.0f), m_spot(0.0f), m_range(1.0f) {
	m_id = LightManager.getNextId();
	m_offset = (float)m_id / LightManager.getWidth() * 2;
}

CLight::CLight(float type, glm::vec3 pos, glm::vec3 color, glm::vec3 dir, glm::vec2 spot, glm::vec4 range) : m_type(type), m_pos(pos), m_color(color), m_dir(dir), m_spot(spot), m_range(range) {
	m_id = LightManager.getNextId();
	m_offset = (float)m_id / LightManager.getWidth() * 2;
}

CLight::~CLight(void) {

}


const float CLight::getOffset(void) {
	return m_offset;
}