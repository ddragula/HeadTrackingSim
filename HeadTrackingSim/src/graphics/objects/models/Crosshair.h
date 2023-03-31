#pragma once

#include "../Model.h"

class Crosshair : public Model
{
public:
	Crosshair();
	Crosshair(const std::string& name, const glm::vec2 position, float size = 1.0f);
	Crosshair(const std::string& name, const glm::vec3 position, const glm::vec3 rotation, float size = 1.0f);

	float getSize() const;
	void setColor(const glm::vec3 color);
private:
	virtual void beforeRender() override;
	void create();
	float size;
	glm::vec3 color;
};