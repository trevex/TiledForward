#include "uniform.h"

CUniform::CUniform(GLuint uniformId) : m_uniformId(uniformId) {

}

CUniform::~CUniform(void) {

}

void CUniform::setMatrix(const float* matrix) {
	glUniformMatrix4fv(m_uniformId, 1, GL_FALSE, matrix);
}


void CUniform::setSamplerId(const GLuint textureId) {
	glUniform1i(m_uniformId, textureId);
}

void CUniform::setFloat(const float value) {
	glUniform1f(m_uniformId, value);
}