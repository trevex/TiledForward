#ifndef _UNIFORM_H_
#define _UNIFORM_H_

#include <GL/glew.h>

class CUniform {
public:
	CUniform(GLuint uniformId);
	~CUniform(void);

	void setMatrix(const float* matrix);
	void setSamplerId(const GLuint textureId);
	void setFloat(const float value);
protected:
private:
	GLuint m_uniformId;
};

#endif