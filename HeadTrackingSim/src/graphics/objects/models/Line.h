#pragma once

#include "../Model.h"

class Line : public Model
{
public:
	Line();
	Line(const std::string& name);
	Line(const std::string& name, const glm::vec3& from, const glm::vec3& to);
	Line(const std::string& name, const glm::vec2& from, const glm::vec2& to);

	void setShader(Shader* shader);

	const glm::vec3& getSize() const;
private:
	void create();
};