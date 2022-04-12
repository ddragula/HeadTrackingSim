#pragma once

#include <unordered_map>
#include <string>

#include "../graphics/Shader.h"

class Shaders
{
public:
	Shaders();
	void loadAll();
	void unloadAll();
	void enable(const std::string& id);
	void disable(const std::string& id);
private:
	std::unordered_map<std::string, Shader*> registry;
};
