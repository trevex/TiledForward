#include <iostream>

#include "fbo.h"
#include "quad.h"
#include "renderer.h"

CFBO::CFBO(GLsizei width, GLsizei height, bool hasDepth) : m_fbo(0), m_texture(0), m_width(width), m_height(height), m_hasDepth(hasDepth) {
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_FALSE); // ALWAYS AUTOMATICALLY!
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glGenFramebuffers(1, &m_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture, 0);

	if (m_hasDepth) {
		glGenRenderbuffers(1, &m_depth);
		glBindRenderbuffer(GL_RENDERBUFFER, m_depth);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depth);
	}

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if(status != GL_FRAMEBUFFER_COMPLETE) {
		std::cout << "FBO was not properly initialized." << std::endl;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

CFBO::~CFBO(void) {
	glDeleteFramebuffers(1, &m_fbo);
	glDeleteTextures(1, &m_texture);
	if (m_hasDepth) glDeleteRenderbuffers(1, &m_depth);
}

void CFBO::bind(void) {
	if (!m_hasDepth) glDisable(GL_DEPTH_TEST);
	glViewport(0, 0, m_width, m_height);
	glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void CFBO::clear(void) {
	if (m_hasDepth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
}

void CFBO::unbind(void) {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	if (!m_hasDepth) glEnable(GL_DEPTH_TEST);
	Renderer.resetViewport();
}

const GLuint CFBO::get(void) const {
	return m_texture;
}

void CFBO::mipmap(void) {
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void CFBO::fullQuad(void) {
	Quad.render();
}