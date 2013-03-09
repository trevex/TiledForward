#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#define DIRECTIONAL_LIGHT 0.0f
#define POINT_LIGHT 0.5f
#define SPOT_LIGHT 1.0f

#define LightManager CLightManager::instance()

class CLightManager {
public:
	CLightManager(void);
	~CLightManager(void);
	
	static CLightManager& instance(void);

	bool initialize(unsigned int maxLights);
	unsigned int getNextId(void);
	unsigned int getWidth(void) const;
	unsigned int getHeight(void) const;
	void renderLightQuad(void);
protected:
private:
	unsigned int m_maxLights;
	unsigned int m_currentId;

	GLuint m_vertexArray;
};


/* TODO: Optimize creation, initialization */
class CLight {
public:
	CLight(void);
	CLight(float type, glm::vec3 pos, glm::vec3 color, glm::vec3 dir, glm::vec2 spot, glm::vec4 range);
	~CLight(void);

	const float getOffset(void);
protected:
private:
	float m_type;
	glm::vec3 m_pos;
	glm::vec3 m_color;
	glm::vec3 m_dir;
	glm::vec2 m_spot;
	glm::vec4 m_range;

	unsigned int m_id;
	float m_offset;
};

#endif