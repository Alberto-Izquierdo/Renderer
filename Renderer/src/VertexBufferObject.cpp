#include "VertexBufferObject.h"
#include <GL\glew.h>

VertexBufferObject::VertexBufferObject(unsigned int _iSize, void* _pData)
{
	glGenBuffers(1, &m_iRendererID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, _iSize, _pData, GL_STATIC_DRAW);
	Unbind();
}
VertexBufferObject::~VertexBufferObject()
{

}

void VertexBufferObject::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_iRendererID);
}

void VertexBufferObject::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
