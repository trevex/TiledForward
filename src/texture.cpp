#include <iostream>
#include <GL/glew.h>

#include "texture.h"

CTexture::CTexture(const std::string filepath) : m_id(0) {
	std::string filetype = filepath.substr(filepath.size() - 3);
	if (filetype == "tga") loadTGA(filepath.c_str());
}

CTexture::~CTexture(void) {

}

void CTexture::loadTGA(const char* filepath) {
	std::cout << "Loading Texture: " << filepath << std::endl;
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	glfwLoadTexture2D(filepath, 0);
	// Trilinear filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
	glGenerateMipmap(GL_TEXTURE_2D);
}

const GLuint CTexture::get(void) const {
	return m_id;
}


void CTexture::bind(GLuint unit) {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_id);
}