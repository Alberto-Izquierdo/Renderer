#include "VertexArrayObject.h"
#include "VertexBufferLayout.h"
#include "VertexBufferObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &m_iRendererID);
}

VertexArrayObject::~VertexArrayObject()
{
}

void VertexArrayObject::AddBuffer(VertexBufferObject& _vb, VertexBufferLayout& _Layout)
{
	Bind();
	_vb.Bind();
	const std::vector<VertexBufferElement> vElements = _Layout.GetElements();
	int offset = 0;

	for (int i = 0, iSize = vElements.size(); i < iSize; ++i)
	{
		VertexBufferElement element = vElements.at(i);
		glVertexAttribPointer(i, element.iCount, element.iType, element.cNormalized, _Layout.GetStride(), (void*)offset);
		offset += VertexBufferElement::GetSizeOfType(element.iType) * element.iCount;
	}
}

void VertexArrayObject::Bind()
{
	glBindVertexArray(m_iRendererID);
}

void VertexArrayObject::Unbind()
{
	glBindVertexArray(0);
}
