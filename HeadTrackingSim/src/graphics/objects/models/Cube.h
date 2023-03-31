#pragma once

#include "../Model.h"

class Cube : public Model
{
public:
	Cube();
	Cube(const std::string& name);
	Cube(const std::string& name, const glm::vec3& size);
	Cube(const std::string& name, const glm::vec3& size, const glm::vec3 position);

	void setShader(Shader* shader);

	const glm::vec3& getSize() const;
private:
	void create();
	glm::vec3 size;
};