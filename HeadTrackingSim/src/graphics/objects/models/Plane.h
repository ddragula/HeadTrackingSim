#pragma once

#include "Model.h"

class Plane : public Model
{
public:
	Plane();
	Plane(const std::string& name);
	Plane(const std::string& name, const glm::vec2& size);
	Plane(const std::string& name, const glm::vec2& size, const glm::vec3& position, const glm::vec3& rotation);

	void setShader(Shader* shader);

	const glm::vec2& getSize() const;
private:
	void create();
	glm::vec2 size;
};