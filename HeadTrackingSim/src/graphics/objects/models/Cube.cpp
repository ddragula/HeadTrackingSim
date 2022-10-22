#include "Cube.h"

Cube::Cube() : Model(), size(1.0f, 1.0f, 1.0f) {}

Cube::Cube(const std::string& name, const glm::vec3& size) : Model(name), size(size) {}

Cube::Cube(const std::string& name, const glm::vec3& size, const glm::vec3 position) : Model(name)
{
	this->setPosition(position);
}

const glm::vec3& Cube::getSize() const
{
	return size;
}
