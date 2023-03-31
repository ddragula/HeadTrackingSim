#include "Model.h"

#include "../../App.h"
#include "../../utils/Debug.h"

Model::Model() : Model("Unnamed Model", nullptr, nullptr) {}

Model::Model(const std::string& name) : Model(name, nullptr, nullptr) {}

Model::Model(const std::string& name, const glm::vec3& position, const glm::vec3& rotation)
	: Model(name, position, rotation, nullptr, nullptr) {}

Model::Model(const std::string& name, VertexArray* vertexArray, Shader* shader)
	: Model(name, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, vertexArray, shader) {}

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

glm::mat4 Model::renderSelf(const glm::mat4& model) const
{
	glm::mat4 nm = modelTransform(model);

	shader->enable();
	shader->setUniformMx4f("model", glm::scale(nm, scale_));
	vertexArray->render();

	return nm;
}


