#include "Crosshair.h"

#include "../../../registry/ShadersRegistry.h"
#include "../../../utils/Debug.h"
#include "../../../App.h"

Crosshair::Crosshair() : Crosshair("crosshair", { 0.0f, 0.0f }, 2.0f) {}

Crosshair::Crosshair(const std::string& name, const glm::vec2 position, float size)
	: Crosshair(name, { position.x, position.y, 0.0f }, { 0.0f, 0.0f, 0.0f }, size) {}

Crosshair::Crosshair(const std::string& name, const glm::vec3 position, const glm::vec3 rotation, float size)
	: Model(name, position, rotation), size(size), color({ 1.0f, 1.0f, 1.0f })
{
	create();
	Model::setShader(ShadersRegistry::get("color"));
}

float Crosshair::getSize() const
{
	return size;
}

void Crosshair::setColor(const glm::vec3 color)
{
	this->color = color;
}

void Crosshair::beforeRender()
{
	const int width = App::getInstance()->getWidth();
	const int height = App::getInstance()->getHeight();

	this->setPosition({ width / 2, height / 2, 0 });
	shader->setUniform3f("color", color);
}

void Crosshair::create()
{
	float vertices[] = {
		-size - 1.0f, 0.0f, 0.0f,
		 size, 0.0f, 0.0f,
		 0.0f, -size, 0.0f,
		 0.0f,  size + 1, 0.0f,
	};

	setVertexArray(new VertexArray(vertices, sizeof(vertices), VertexArray::Lines));
}
