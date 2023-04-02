#include "RegularPolygon.h"
#include "../../../utils/Debug.h"
#include "../../../registry/ShadersRegistry.h"

#include <cmath>
#include <vector>

const double DOUBLE_PI = std::acos(-1) * 2.0;

RegularPolygon::RegularPolygon() : RegularPolygon("RegularPolygon", { 0.0f, 0.0f })
{
}

RegularPolygon::RegularPolygon(const std::string& name, const glm::vec2 position, unsigned int n, float radius)
	: RegularPolygon(name, { position.x, position.y, 0.0f }, { 0.0f, 0.0f, 0.0f }, n, radius)
{
}

RegularPolygon::RegularPolygon(const std::string& name, const glm::vec3 position, const glm::vec3 rotation, unsigned int n, float radius)
	: Model(name, position, rotation), radius(radius), n(n), color({ 1.0f, 1.0f, 1.0f })
{
	create();
	Model::setShader(ShadersRegistry::get("color"));
}

float RegularPolygon::getRadius() const
{
	return radius;
}

unsigned int RegularPolygon::getN() const
{
	return n;
}

void RegularPolygon::setColor(const glm::vec3 color)
{
	this->color = color;
}

void RegularPolygon::beforeRender()
{
	shader->setUniform3f("color", color);
}

void RegularPolygon::create()
{
	if (n < 3) {
		Debug::error("A polygon should have at least 3 vertices.");
	}
	
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	float dn = static_cast<double>(n);

	for (int i = 0; i < n; i++)
	{
		float angle = i / dn * DOUBLE_PI;

		vertices.push_back(std::sin(angle) * radius);
		vertices.push_back(std::cos(angle) * radius);
		vertices.push_back(0.0f);
	}

	for (int i = 0; i < n - 1; i++)
	{
		indices.push_back(i);
		indices.push_back(i + 1);
	}

	indices.push_back(n - 1);
	indices.push_back(0);

	setVertexArray(new VertexArray(vertices.data(), vertices.size() * sizeof(float), indices.data(), indices.size() * sizeof(unsigned int), VertexArray::Lines));
}
