#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glew.h>

#include "shader.h"

std::string fileToString(const char* file) {
	std::string result = "";
	std::ifstream inFileStream(file, std::ios::in);
	if (inFileStream.is_open()) {
		std::string Line = "";
		while (getline(inFileStream, Line))
			result += "\n" + Line;
		inFileStream.close();
	}
	return result;
}

CShader::CShader(const char* vertFile, const char* fragFile) : m_program(0){
	m_program = glCreateProgram();
	if (vertFile && fragFile) load(vertFile, fragFile);
}

CShader::~CShader(void) {
	glDeleteProgram(m_program);
}

void CShader::use(void) {
	glUseProgram(m_program);
}

bool CShader::load(const char* vertFile, const char* fragFile) {
	bool result = true;
	// Create shader ids
	GLuint vertId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragId = glCreateShader(GL_FRAGMENT_SHADER);

	// Read shader files
	std::string vertSrc, fragSrc;
	if ((vertSrc = fileToString(vertFile)) == "") std::cout << "Unable to open vertex shader file!" << std::endl;
	if ((fragSrc = fileToString(fragFile)) == "") std::cout << "Unable to open fragment shader file!" << std::endl;

	// Compile vertex shader
	std::cout << "Compiling shader : " << vertFile << std::endl;
	if (!compile(vertId, vertSrc)) result = false;

	// Compile fragment shader
	std::cout << "Compiling shader : " << fragFile << std::endl;
	if (!compile(fragId, fragSrc)) result = false;

	// Link program
	std::cout << "Linking program..." << std::endl;
	if (link(vertId, fragId)) result = false;

	glDeleteShader(vertId);
	glDeleteShader(fragId);

	return result;
}

bool CShader::compile(GLuint &id, std::string &src) {
	GLint result = GL_FALSE;
	int infoLogLength = 0;

	// Compile shader
	const char* srcPtr = src.c_str();
	glShaderSource(id, 1, &srcPtr, NULL);
	glCompileShader(id);

	// Check Shader
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> errMsg(infoLogLength+1);
		glGetShaderInfoLog(id, infoLogLength, NULL, &errMsg[0]);
		std::cout << &errMsg[0] << std::endl;
	}
	if (result == GL_FALSE) {
		return false;
	}
	return true;
}

bool CShader::link(GLuint &vert, GLuint &frag) {
	GLint result = GL_FALSE;
	int infoLogLength = 0;

	glAttachShader(m_program, vert);
	glAttachShader(m_program, frag);
	glLinkProgram(m_program);

	// Check the program
	glGetProgramiv(m_program, GL_LINK_STATUS, &result);
	glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0) {
		std::vector<char> errMsg(infoLogLength+1);
		glGetProgramInfoLog(m_program, infoLogLength, NULL, &errMsg[0]);
		std::cout << &errMsg[0] << std::endl;
	}
	if (result == GL_FALSE) {
		return false;
	}
	return true;
}


GLuint CShader::getUniform(const char* name) {
	return glGetUniformLocation(m_program, name);
}