#include "IndexBuffer.h"
#include <tools/gltools.hpp>

void IndexBuffer::initialize()
{
}

void IndexBuffer::destroy()
{
	if (m_ibo != 0) {
		GL_ASSERT(glDeleteBuffers(1, &m_ibo));
		m_ibo = 0;
	}
}

void IndexBuffer::create(std::vector<unsigned int>& indices)
{
	m_NumIndices = indices.size();

    GL_ASSERT(glGenBuffers(1, &m_ibo));
	bind();
    GL_ASSERT(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*m_NumIndices, indices.data(), GL_STATIC_DRAW));
	unbind();
}

void IndexBuffer::bind()
{
    GL_ASSERT(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo));
}

void IndexBuffer::unbind()
{
	GL_ASSERT(glBindBuffer( GL_ARRAY_BUFFER, 0u));
}

void IndexBuffer::enable()
{
	bind();
}

void IndexBuffer::disable()
{
	unbind();
}