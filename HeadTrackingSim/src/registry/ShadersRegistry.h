#pragma once

#include <unordered_map>
#include <string>

#include "../graphics/Shader.h"

class ShadersRegistry
{
private:
	ShadersRegistry() = delete;
public:
	static void loadAll();
	static void unloadAll();
	static void enable(const std::string& name);
	static void disable(const std::string& name);
	static Shader* get(const std::string& name);
	static void setVPMatrix(const glm::mat4& vp);
private:
	static std::unordered_map<std::string, Shader*> registry;
};
