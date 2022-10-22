#pragma once
#include <string>
#include <vector>
#include "glm/glm.hpp";

enum ObjectType
{
	Empty,
	Camera,
	Model
};

class Object
{
public:
	Object();
	Object(const std::string& name);
	Object(const std::string& name, const glm::vec3& position, const glm::vec3& rotation);

	const ObjectType type = ObjectType::Empty;
	const std::string& getName() const;

	void setPosition(const glm::vec3& position);
	void setRotation(const glm::vec3& rotation);
	const glm::vec3& getPosition();
	const glm::vec3& getRotation();

	void translate(const glm::vec3& vertex);
	void rotate(const glm::vec3& vertex);

	void addChild(Object* child);
	Object* getParent() const;
	const std::vector<Object*>& getChildren() const;
	unsigned int getChildrenAmount() const;

	virtual void render() const;
protected:
	bool canBeParentOf(Object* object) const;
private:
	const std::string name;
	glm::vec3 position;
	glm::vec3 rotation;
	Object* parent;
	std::vector<Object*> children;
};