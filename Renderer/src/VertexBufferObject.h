#pragma once

class VertexBufferObject
{
public:
	VertexBufferObject(unsigned int _iSize, void* _pData);
	~VertexBufferObject();

	void Bind();
	void Unbind();

private:
	unsigned int m_iRendererID;
};
