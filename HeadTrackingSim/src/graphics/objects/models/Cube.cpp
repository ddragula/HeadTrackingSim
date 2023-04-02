#include "Cube.h"

#include "../../../utils/Debug.h"

Cube::Cube() : Cube("Unnamed Cube", { 1.0f, 1.0f, 1.0f }) {}

Cube::Cube(const std::string& name, const glm::vec3& size) : Cube(name, size, { 0.0f, 0.0f, 0.0f })
{
}

Cube::Cube(const std::string& name, const glm::vec3& size, const glm::vec3& position) : Model(name, position, { 0.0f, 0.0f, 0.0f }), size(size)
{
	create();
}

void Cube::setShader(Shader* shader)
{
	Model::setShader(shader);
}

const glm::vec3& Cube::getSize() const
{
	return size;
}

void Cube::create()
{
	float x = size.x / 2.0f;
	float y = size.y / 2.0f;
	float z = size.z / 2.0f;

	float vertices[] = {
		-x,  y, -z,
		-x, -y, -z,
		 x, -y, -z,
		 x,  y, -z,
		-x,  y,  z,
		-x, -y,  z,
		 x, -y,  z,
		 x,  y,  z
	};

	unsigned int indices[] = {
		// back
		0, 1, 2,
		2, 3, 0,

		// front
		4, 5, 6,
		6, 7, 4,

		// top
		0, 4, 7,
		7, 3, 0,

		// bottom
		1, 5, 6,
		6, 2, 1,

		// left
		0, 1, 5,
		5, 4, 0,

		// right
		3, 2, 6,
		6, 7, 3
	};

	float uv[] = {
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f
	};

	setVertexArray(new VertexArray(vertices, sizeof(vertices), indices, sizeof(indices), uv, sizeof(uv), VertexArray::Solid));
}
