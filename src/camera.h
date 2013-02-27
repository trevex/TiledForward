#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>

#define Camera CCamera::instance()

class CCamera {
public:
	CCamera(void);
	~CCamera(void);

	static CCamera& instance(void);

	const float* getMVP(const glm::mat4 &model);
	void setPosition(const glm::vec3 &position);
	void lookAt(const glm::vec3 &target);
	void setAspect(float ratio);
protected:
private:
	glm::vec3 m_position;
	glm::vec3 m_target;
	glm::mat4 m_proj;
	glm::mat4 m_view;
	glm::mat4 m_vp;
	glm::mat4 m_mvp;
	float m_aspect;

	bool m_changed;
};

#endif