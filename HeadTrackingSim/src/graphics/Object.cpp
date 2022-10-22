#include "Object.h"
#include "../utils/Debug.h";
#include <algorithm>

Object::Object() : Object("unnamed-object") {}

Object::Object(const std::string& name) : Object(name, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)) {}

Object::Object(const std::string& name, const glm::vec3& position, const glm::vec3& rotation)
	: name(name), position(position), rotation(rotation), parent(nullptr), children() {}

const std::string& Object::getName() const
{
	return this->name;
}

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

void Object::addChild(Object* child)
{
	if (!child)
	{
		Debug::error("Adding the child to the '" + name + "' failed because the child does not exist");
		return;
	}

	if (!this->canBeParentOf(child))
	{
		Debug::error("'" + child->getName() + "' cannot be assigned as a child of '" + name + "'");
		return;
	}

	if (child->parent)
	{
		auto &vec = child->parent->children;
		vec.erase(std::remove(vec.begin(), vec.end(), child), vec.end());
	}

	child->parent = this;
	this->children.push_back(child);
	Debug::log("'" + child->name + "' has been added as a child of '" + name + "'");
}

Object* Object::getParent() const
{
	return this->parent;
}

const std::vector<Object*>& Object::getChildren() const
{
	return this->children;
}

unsigned int Object::getChildrenAmount() const
{
	return this->children.size();
}

void Object::render() const
{
}

bool Object::canBeParentOf(Object* object) const
{
	if (object == this)
	{
		return false;
	}

	for (const auto child : object->children)
	{
		if (!canBeParentOf(child))
		{
			return false;
		}
	}

	return true;
}
