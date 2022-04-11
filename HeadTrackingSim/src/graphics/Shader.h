#pragma once
#include <string>
#include <glm/glm.hpp>

constexpr  int VERTEX_ATTRIB = 0;
constexpr int TCOORD_ATTRIB = 1;

class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
private:
	void load(const std::string& vertexPath, const std::string& fragmentPath);
	void create(const std::string& vertexSource, const std::string& fragmentSource);
	bool enabled;
	int id;
public:
	void setUniform1i(const std::string& name, int value);
	void setUniform1f(const std::string& name, float value);
	void setUniform2f(const std::string& name, float x, float y);
	void setUniform3f(const std::string& name, const glm::vec3& vec);
	void setUniformMx4f(const std::string& name, const glm::mat4& mat);
	void enable();
	void disable();
};