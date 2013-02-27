#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>
#include <GL/glfw.h>

class CTexture {
public:
	CTexture(const std::string filepath);
	CTexture(GLuint texture);
	~CTexture(void);

	const GLuint get(void) const;
	void bind(GLuint unit = 0);
protected:
private:
	void loadTGA(const char* filepath);

	GLuint m_id;
};

#endif