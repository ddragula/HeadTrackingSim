#include "Model.h"

Model::Model() : Object(), shader(nullptr), vertexArray(nullptr) {}

Model::Model(const std::string& name) : Object(name), shader(nullptr), vertexArray(nullptr) {}

Model::Model(const std::string& name, const glm::vec3& position, const glm::vec3& rotation)
	: Object(name, position, rotation), shader(nullptr), vertexArray(nullptr) {}

Model::Model(const std::string& name, VertexArray* vertexArray, Shader* shader)
	: Object(name), shader(shader), vertexArray(vertexArray) {}

Model::Model(const std::string& name, const glm::vec3& position, const glm::vec3& rotation, VertexArray* vertexArray, Shader* shader)
	: Object(name, position, rotation), shader(shader), vertexArray(vertexArray) {}

void Model::setVertexArray(VertexArray* vertexArray)
{
	this->vertexArray = vertexArray;
}

void Model::setShader(Shader* shader)
{
	this->shader = shader;
}

void Model::render() const
{
	shader->enable();
	vertexArray->render();
}


