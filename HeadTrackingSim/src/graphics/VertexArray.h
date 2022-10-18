#pragma once
#include <glm/glm.hpp>

class VertexArray
{
public:
	static unsigned int VERTEX_ATTRIB;
	static unsigned int TCOORD_ATTRIB;
public:
	VertexArray();
	void create(float vertices[], size_t verticesSize, unsigned int indices[], size_t indicesSize, float uv[], size_t uvSize);
	void bind();
	void unbind();
	void draw();
	void render();
private:
	unsigned int vao, vbo, ibo, tbo;
	unsigned int count;
};