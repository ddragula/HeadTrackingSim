#include "VertexArray.h"
#include <glad/glad.h>

unsigned int VertexArray::VERTEX_ATTRIB = 0;
unsigned int VertexArray::TCOORD_ATTRIB = 1;

VertexArray::VertexArray() : vao(0), vbo(0), tbo(0), ibo(0), count(0) {}

VertexArray::VertexArray(float vertices[], size_t verticesSize, unsigned int indices[], size_t indicesSize, float uv[], size_t uvSize) : VertexArray()
{
	if (indices == nullptr)
	{
		this->count = verticesSize / sizeof(float);
	}
	else
	{
		this->count = indicesSize / sizeof(unsigned int);
	}

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(VERTEX_ATTRIB, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	if (uv != nullptr)
	{
		glGenBuffers(1, &tbo);
		glBindBuffer(GL_ARRAY_BUFFER, tbo);
		glBufferData(GL_ARRAY_BUFFER, uvSize, uv, GL_STATIC_DRAW);
		glVertexAttribPointer(TCOORD_ATTRIB, 2, GL_FLOAT, GL_FALSE, 0, 0);
	}

	if (indices != nullptr)
	{
		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexArray::bind()
{
	glBindVertexArray(vao);
	if (ibo > 0)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	}
}

void VertexArray::unbind()
{
	if (ibo > 0)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	glBindVertexArray(0);
}

void VertexArray::draw()
{
	if (ibo > 0) {
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, count);
	}
}

void VertexArray::render()
{
	bind();
	draw();
}


