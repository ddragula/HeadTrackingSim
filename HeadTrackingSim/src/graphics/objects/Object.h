#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>;
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object
{
public:
	enum ObjectType
	{
		Empty,
		Camera,
		Model
	};
public:
	Object();
	Object(const std::string& name);
	Object(const std::string& name, const glm::vec3& position, const glm::vec3& rotation);

	const ObjectType type = ObjectType::Empty;
	const std::string& getName() const;

	void setPosition(const glm::vec3& position);
	void setRotation(const glm::vec3& rotation);
	void setScale(const glm::vec3& scale);
	const glm::vec3& getPosition() const;
	const glm::vec3& getRotation() const;
	const glm::vec3& getScale() const;

	void setEnabled(bool enabled);
	bool isEnabled() const;

	void translate(const glm::vec3& vertex);
	void rotate(const glm::vec3& vertex);

	void addScale(const glm::vec3& vertex);
	void multiplyScale(const glm::vec3& vertex);

	void addChild(Object* child);
	Object* getParent() const;
	const std::vector<Object*>& getChildren() const;
	unsigned int getChildrenAmount() const;

	void render() const;
	void render(const glm::mat4& model) const;

	glm::mat4 modelTransform(const glm::mat4& model) const;
protected:
	virtual glm::mat4 renderSelf(const glm::mat4& model) const;
	bool canBeParentOf(const Object* object) const;
	const std::string name;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale_;
private:
	Object* parent;
	std::vector<Object*> children;
	bool enabled;
};