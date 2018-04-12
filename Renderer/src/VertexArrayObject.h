#pragma once

class VertexBufferLayout;
class VertexBufferObject;

class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();

	void VertexArrayObject::AddBuffer(VertexBufferObject& _vb, VertexBufferLayout& _Layout);

	void Bind();
	void Unbind();
private:
	unsigned int m_iRendererID;
};
