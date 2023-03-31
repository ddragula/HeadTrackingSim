#include "Object.h"
#include "../../utils/Debug.h";
#include <algorithm>

Object::Object() : Object("unnamed-object") {}

Object::Object(const std::string& name) : Object(name, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)) {}

Object::Object(const std::string& name, const glm::vec3& position, const glm::vec3& rotation)
	: name(name), position(position), rotation(rotation), parent(nullptr), children(), enabled(true), scale_(1.0f, 1.0f, 1.0f) {}

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

void Object::setScale(const glm::vec3& scale)
{
	this->scale_ = scale;
}

const glm::vec3& Object::getPosition() const
{
	return position;
}

const glm::vec3& Object::getRotation() const
{
	return rotation;
}

const glm::vec3& Object::getScale() const
{
	return scale_;
}

void Object::setEnabled(bool enabled)
{
	this->enabled = enabled;
}

bool Object::isEnabled() const
{
	return enabled;
}

void Object::translate(const glm::vec3& vertex)
{
	position += vertex;
}

void Object::rotate(const glm::vec3& vertex)
{
	rotation += vertex;
}

void Object::addScale(const glm::vec3& vertex)
{
	this->scale_ += vertex;
}

void Object::multiplyScale(const glm::vec3& vertex)
{
	this->scale_ *= vertex;
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

void Object::beforeRender()
{
}

glm::mat4 Object::renderSelf(const glm::mat4& model) const
{
	return modelTransform(model);
}

void Object::render()
{
	render(glm::mat4(1.0f));
}

void Object::render(const glm::mat4& model)
{
	if (isEnabled())
	{
		beforeRender();
		const glm::mat4 nm = renderSelf(model);
		for (const auto child : children)
		{
			child->render(nm);
		}
	}
}

bool Object::canBeParentOf(const Object* object) const
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

glm::mat4 Object::modelTransform(const glm::mat4& model) const
{
	glm::mat4 nm = glm::translate(model, position);
	nm = glm::rotate(nm, glm::radians(rotation.x), { 1.0f, 0.0f, 0.0f });
	nm = glm::rotate(nm, glm::radians(rotation.y), { 0.0f, 1.0f, 0.0f });
	nm = glm::rotate(nm, glm::radians(rotation.z), { 0.0f, 0.0f, 1.0f });
	return nm;
}

