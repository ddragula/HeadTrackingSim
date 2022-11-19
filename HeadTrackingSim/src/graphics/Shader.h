#pragma once
#include <string>
#include <glm/glm.hpp>

constexpr  int VERTEX_ATTRIB = 0;
constexpr int TCOORD_ATTRIB = 1;

class Shader
{
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	void load(const std::string& vertexPath, const std::string& fragmentPath);
private:
	void create(const std::string& vertexSource, const std::string& fragmentSource);
	bool enabled;
	int id;
public:
	void setUniform1i(const std::string& name, int value) const;
	void setUniform1f(const std::string& name, float value) const;
	void setUniform2f(const std::string& name, float x, float y) const;
	void setUniform3f(const std::string& name, const glm::vec3& vec) const;
	void setUniformMx4f(const std::string& name, const glm::mat4& mat) const;
	void enable();
	void disable();
private:
	glm::mat4 vpMat;
public:
	void setVPMat(const glm::mat4& vpm);
};
