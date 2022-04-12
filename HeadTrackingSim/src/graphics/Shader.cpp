#include "Shader.h"

#include "../utils/FileUtils.h"
#include "../utils/Debug.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) : enabled(false), id(0)
{
	Debug::log("Loading the shader: (vertex: \"" + vertexPath + "\", fragment: \"" + fragmentPath + "\")");
	load(vertexPath, fragmentPath);
}

void Shader::load(const std::string& vertexPath, const std::string& fragmentPath)
{
	const std::string& vertexSource = FileUtils::loadToString(vertexPath);
	const std::string& fragmentSource = FileUtils::loadToString(fragmentPath);
	create(vertexSource, fragmentSource);
}

void Shader::create(const std::string& vertexSource, const std::string& fragmentSource)
{
	const int program = glCreateProgram();
	const int vId = glCreateShader(GL_VERTEX_SHADER);
	const int fId = glCreateShader(GL_FRAGMENT_SHADER);

	const char* const vss[] = { vertexSource.c_str() };
	const char* const fss[] = { fragmentSource.c_str() };

	glShaderSource(vId, 1, vss, nullptr);
	glShaderSource(fId, 1, fss, nullptr);

	int success;
	char infoLog[512];

	// Vertex
	glCompileShader(vId);
	glGetShaderiv(vId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vId, 512, nullptr, infoLog);
		Debug::error("Vertex shader compilation error");
		Debug::longLog("Error log", infoLog);
	}

	// Fragment
	glCompileShader(fId);
	glGetShaderiv(fId, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fId, 512, nullptr, infoLog);
		Debug::error("Fragment shader compilation error");
		Debug::longLog("Error log", infoLog);
	}

	// Program
	glAttachShader(program, vId);
	glAttachShader(program, fId);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, nullptr, infoLog);
		Debug::error("Program shader linking error");
		Debug::longLog("Error log", infoLog);
	}

	glDeleteShader(vId);
	glDeleteShader(fId);

	id = program;
}

void Shader::setUniform1i(const std::string& name, const int value)
{
	if (!enabled) enable();
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setUniform1f(const std::string& name, const float value)
{
	if (!enabled) enable();
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setUniform2f(const std::string& name, const float x, const float y)
{
	if (!enabled) enable();
	glUniform2f(glGetUniformLocation(id, name.c_str()), x, y);
}

void Shader::setUniform3f(const std::string& name, const glm::vec3& vec)
{
	if (!enabled) enable();
	glUniform3f(glGetUniformLocation(id, name.c_str()), vec.x, vec.y, vec.z);
}

void Shader::setUniformMx4f(const std::string& name, const glm::mat4& mat)
{
	if (!enabled) enable();
	glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::enable()
{
	glUseProgram(id);
	enabled = true;
}

void Shader::disable()
{
	glUseProgram(0);
	enabled = false;
}
