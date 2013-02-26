#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <GL/glfw.h>

class CShader {
public:
	CShader(const char* vertFile = NULL, const char* fragFile = NULL);
	~CShader(void);

	bool load(const char* vertFile, const char* fragFile);
	void use(void);
protected:
private:
	bool compile(GLuint &id, std::string &src);
	bool link(GLuint &vert, GLuint &frag);

	GLuint m_program;
};

#endif