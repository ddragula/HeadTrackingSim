#include "ShadersRegistry.h"

#include <fstream>
#include <nlohmann/json.hpp>

#include "../utils/Debug.h"
#include "../utils/FileUtils.h"

using json = nlohmann::json;

std::unordered_map<std::string, Shader*> ShadersRegistry::registry;

void ShadersRegistry::loadAll()
{
	Debug::log("Loading all shaders...");

	json shadersConfig = json::parse(std::ifstream("resources/shaders.json"));

	for (json::iterator it = shadersConfig.begin(); it != shadersConfig.end(); ++it) {
		registry[it.key()] = new Shader(
			"resources/" + static_cast<std::string>(it.value()["vertex"]),
			"resources/" + static_cast<std::string>(it.value()["fragment"])
		);
	}
}

void ShadersRegistry::setVPMatrix(const glm::mat4& vp)
{
	for (auto& pair : registry)
	{
		pair.second->setVPMat(vp);
	}
}

void ShadersRegistry::unloadAll()
{
	Debug::log("Unloading shaders...");
	for (auto &record: registry)
	{
		delete record.second;
		record.second = nullptr;
	}
	Debug::log("Shaders have been unloaded");
}


void ShadersRegistry::enable(const std::string& name)
{
	registry[name]->enable();
}

void ShadersRegistry::disable(const std::string& name)
{
	registry[name]->disable();
}

Shader* ShadersRegistry::get(const std::string& name)
{
	return registry[name];
}
