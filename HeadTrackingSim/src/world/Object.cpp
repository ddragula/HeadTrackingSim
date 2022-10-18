#include "Object.h"

Object::Object(const std::string& id) : id(id), position(0, 0, 0), rotation(0, 0, 0) {}

Object::Object(const std::string& id, const glm::vec3& position, const glm::vec3& rotation) : id(id), position(position), rotation(rotation) {}

void Object::setPosition(const glm::vec3& position)
{
	this->position = position;
}

void Object::setRotation(const glm::vec3& rotation)
{
	this->rotation = rotation;
}

const glm::vec3& Object::getPosition()
{
	return position;
}

const glm::vec3& Object::getRotation()
{
	return rotation;
}

void Object::translate(const glm::vec3& vertex)
{
	position += vertex;
}

void Object::rotate(const glm::vec3& vertex)
{
	rotation += vertex;
}
