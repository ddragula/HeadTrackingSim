#pragma once
#include <glm/glm.hpp>

class VertexArray
{
public:
	enum DrawMode {
		Points = 0,
		Lines = 1,
		Solid = 4
	};
public:
	static unsigned int VERTEX_ATTRIB;
	static unsigned int TCOORD_ATTRIB;
public:
	VertexArray();
	VertexArray(float vertices[], size_t verticesSize, unsigned int indices[], size_t indicesSize, float uv[], size_t uvSize, DrawMode mode);
	VertexArray(float vertices[], size_t verticesSize, unsigned int indices[], size_t indicesSize, DrawMode mode);
	VertexArray(float vertices[], size_t uvSize, DrawMode mode);
	void bind();
	void unbind();
	void draw();
	void render();
	DrawMode mode;
private:
	unsigned int vao, vbo, ibo, tbo;
	unsigned int count;
};