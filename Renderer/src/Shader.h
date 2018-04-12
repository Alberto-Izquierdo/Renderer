#pragma once

#include <string>
#include <unordered_map>

enum ShaderType
{
	VERTEX,
	FRAGMENT,
};

class Shader
{
public:
	Shader(const std::string& _sVertexSource, const std::string& _sFragmentSource);
	~Shader();

	void Bind();
	void Unbind();

	// set uniforms
private:
	unsigned int m_iRendererID;
	std::unordered_map<std::string, int> m_mUniformLocationCache;

	std::string ParseShader(const std::string& _sSource);
	int CompileShader(const std::string& _sSource, ShaderType _eType);
	void LinkProgram(int _iVertexShader, int _iFragmentShader);
};
