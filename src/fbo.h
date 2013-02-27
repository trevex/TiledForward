#ifndef _FBO_H_
#define _FBO_H_

#include <GL/glew.h>

class CFBO {
public:
	CFBO(GLsizei width = 1024, GLsizei height = 1024, bool hasDepth = false);
	~CFBO(void);

	void bind(void);
	void clear(void);
	void unbind(void);
	const GLuint get(void) const;
	void mipmap(void);
	void fullQuad(void);
protected:
private:
	GLuint m_fbo;
	GLuint m_depth;
	GLuint m_texture;

	GLsizei m_width;
	GLsizei m_height; 

	bool m_hasDepth;
};

#endif