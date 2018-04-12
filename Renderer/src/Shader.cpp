#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

Shader::Shader(const std::string& _sVertexSource, const std::string& _sFragmentSource)
{
	int iVertexShader = CompileShader(_sVertexSource, ShaderType::VERTEX);

	if (iVertexShader == -1)
	{
		m_iRendererID = -1;
		return;
	}

	int iFragmentShader = CompileShader(_sFragmentSource, ShaderType::FRAGMENT);

	if (iFragmentShader == -1)
	{
		m_iRendererID = -1;
		glDeleteShader(iVertexShader);
		return;
	}

	LinkProgram(iVertexShader, iFragmentShader);
}

Shader::~Shader()
{
	glDeleteProgram(m_iRendererID);
}

void Shader::Bind()
{
	glUseProgram(m_iRendererID);
}

void Shader::Unbind()
{
	glUseProgram(0);
}

// set uniforms

// shader load/compilation/link
int Shader::CompileShader(const std::string& _sSource, ShaderType _eType)
{
	std::string sParsedSource = ParseShader(_sSource);
	int iShader = glCreateShader((_eType == ShaderType::VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER));
	const char* src = sParsedSource.c_str();
	glShaderSource(iShader, 1, &src, NULL);
	glCompileShader(iShader);
	int success;
	glGetShaderiv(iShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(iShader, 512, NULL, infoLog);
		std::cout << "ERROR::" << (_eType == ShaderType::VERTEX ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << std::endl;
		return -1;
	}

	return iShader;
}

void Shader::LinkProgram(int _iVertexShader, int _iFragmentShader)
{
	m_iRendererID = glCreateProgram();
	glAttachShader(m_iRendererID, _iVertexShader);
	glAttachShader(m_iRendererID, _iFragmentShader);
	glLinkProgram(m_iRendererID);
	int success;
	glGetShaderiv(m_iRendererID, GL_LINK_STATUS, &success);

	if (!success)
	{
		m_iRendererID = -1;
		char infoLog[512];
		glGetProgramInfoLog(m_iRendererID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(_iVertexShader);
	glDeleteShader(_iFragmentShader);
}

std::string Shader::ParseShader(const std::string& _sSource)
{
	std::ifstream stream(_sSource);

	std::string line;
	std::stringstream ss;

	while (getline(stream, line))
	{
		ss << line << '\n';
	}

	return ss.str();
}
