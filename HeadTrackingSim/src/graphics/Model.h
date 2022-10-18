#pragma once
#include "Shader.h";
#include "VertexArray.h";
#include "../registry/ShadersRegistry.h";
#include "glm/glm.hpp";

class Model
{
public:
	Model();
	void create(VertexArray* vertexArray);
	void setShader(Shaders shader);
	// TODO: void setTexture();
private:
	Shader* shader;
	VertexArray* vertexArray;
};