#pragma once

#include <GL/glew.h>
#include <vector>

struct VertexBufferElement
{
	unsigned int iType;
	unsigned int iCount;
	unsigned char cNormalized;

	static unsigned int GetSizeOfType(unsigned int _iType)
	{
		switch (_iType)
		{
			case GL_FLOAT:
				return 4;

			case GL_UNSIGNED_INT:
				return 4;

			case GL_UNSIGNED_BYTE:
				return 1;
		}

		return 0;
	}
};


class VertexBufferLayout
{
public:
	VertexBufferLayout() : m_iStride(0) {};
	~VertexBufferLayout() {};

	inline unsigned int GetStride() const { return m_iStride; };
	inline const std::vector<VertexBufferElement>& GetElements() const { return m_vElements; };

	template <typename T>
	void Push(unsigned int count)
	{

	};

	template<>
	void Push<float>(unsigned int _iCount)
	{
		m_vElements.push_back({GL_FLOAT, _iCount, GL_FALSE});
		m_iStride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * _iCount;
	}

	template<>
	void Push<unsigned int>(unsigned int _iCount)
	{
		m_vElements.push_back({GL_UNSIGNED_INT, _iCount, GL_FALSE});
		m_iStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * _iCount;
	}

	template<>
	void Push<char>(unsigned int _iCount)
	{
		m_vElements.push_back({GL_UNSIGNED_BYTE, _iCount, GL_TRUE});
		m_iStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * _iCount;
	}
private:
	std::vector<VertexBufferElement> m_vElements;
	unsigned int m_iStride;
};
