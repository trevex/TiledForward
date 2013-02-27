#include <memory>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"

const glm::vec3 gUp(0.0f, 1.0f, 0.0f);

CCamera::CCamera(void) : m_position(5.0f, 5.0f, 5.0f), m_target(0.0f), m_proj(1.0f), m_view(1.0f), m_vp(1.0f), m_mvp(1.0f), m_aspect(4.0f / 3.0f), m_changed(true) {

}

CCamera::~CCamera(void) {

}

CCamera& CCamera::instance(void) {
	static std::unique_ptr<CCamera> ptr(new CCamera());
    return *ptr;
}

const float* CCamera::getMVP(const glm::mat4 &model) {
	if (m_changed) { /* TODO: if necessary far and near could become members of camera as well... */
		m_proj = glm::perspective(45.0f, m_aspect, 0.1f, 100.0f);
		m_view = glm::lookAt(m_position, m_target, gUp);
		m_vp = m_proj * m_view;
		m_changed = false;
	}
	m_mvp = m_vp * model;
	return glm::value_ptr(m_mvp);
}

void CCamera::setPosition(const glm::vec3 &position) {
	m_position = position;
	m_changed = true;
}

void CCamera::lookAt(const glm::vec3 &target) {
	m_target = target;
	m_changed = true;
}

void CCamera::setAspect(float ratio) {
	m_aspect = ratio;
	m_changed = true;
}