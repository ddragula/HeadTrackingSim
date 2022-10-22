#pragma once

#include "../Object.h";
#include "../../Shader.h"
#include "../../VertexArray.h"

class Model : public Object
{
public:
	Model();
	Model(const std::string& name);
	Model(const std::string& name, const glm::vec3& position, const glm::vec3& rotation);
	Model(const std::string& name, VertexArray* vertexArray, Shader* shader);
	Model(const std::string& name, const glm::vec3& position, const glm::vec3& rotation, VertexArray* vertexArray, Shader* shader);

	const ObjectType type = ObjectType::Model;
protected:
	virtual glm::mat4 renderSelf(glm::mat4 model) const override;
	void setVertexArray(VertexArray* vertexArray);
	void setShader(Shader* shader);
	VertexArray* vertexArray;
	Shader* shader;
};