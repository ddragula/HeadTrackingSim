#include "Plane.h"

Plane::Plane() : Model(), size(2.0f, 2.0f)
{
	create();
}

Plane::Plane(const std::string& name) : Model(name), size(2.0f, 2.0f)
{
	create();
}


Plane::Plane(const std::string& name, const glm::vec2& size) : Model(name), size(size)
{
	create();
}

Plane::Plane(const std::string& name, const glm::vec2& size, const glm::vec3& position, const glm::vec3& rotation) : Model(name, position, rotation)
{
	create();
}

void Plane::setShader(Shader* shader)
{
	Model::setShader(shader);
}

const glm::vec2& Plane::getSize() const
{
	return size;
}

void Plane::create()
{
	float vertices[] = {
		-1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	float tcs[] = {
		0, 1,
		0, 0,
		1, 0,
		1, 1
	};

	setVertexArray(new VertexArray(vertices, sizeof(vertices), indices, sizeof(indices), tcs, sizeof(tcs)));
}
