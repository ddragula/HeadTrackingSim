#pragma once
#include <string>
#include "glm/glm.hpp";

class Object
{
public:
	Object(const std::string& id);
	Object(const std::string& id, const glm::vec3& position, const glm::vec3& rotation);

	void setPosition(const glm::vec3& position);
	void setRotation(const glm::vec3& rotation);
	const glm::vec3& getPosition();
	const glm::vec3& getRotation();

	void translate(const glm::vec3& vertex);
	void rotate(const glm::vec3& vertex);
private:
	const std::string id;
	glm::vec3 position;
	glm::vec3 rotation;
};