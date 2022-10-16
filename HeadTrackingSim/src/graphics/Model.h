#pragma once
#include <glm/glm.hpp>

class Model
{
public:
	Model();
	void create(float vertices[], size_t size);
	void draw();
private:
	unsigned int VBO, VAO;
};