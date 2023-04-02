#pragma once

#include "../Model.h"

class RegularPolygon : public Model
{
public:
	RegularPolygon();
	RegularPolygon(const std::string& name, const glm::vec2 position, unsigned int n = 5U, float radius = 50.0f);
	RegularPolygon(const std::string& name, const glm::vec3 position, const glm::vec3 rotation, unsigned int n = 5U, float radius = 1.0f);

	float getRadius() const;
	unsigned int getN() const;
	void setColor(const glm::vec3 color);
private:
	virtual void beforeRender() override;
	void create();
	const float radius;
	const unsigned int n;
	glm::vec3 color;
};