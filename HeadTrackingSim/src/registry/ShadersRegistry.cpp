#include "ShadersRegistry.h"

#include "../utils/Debug.h";

std::unordered_map<ShadersRegistry::Shaders, Shader*> ShadersRegistry::registry;

void ShadersRegistry::loadAll()
{
	Debug::log("Loading all shaders...");

	registry[Basic] = new Shader("shaders/basic.vert", "shaders/basic.frag");
	registry[Fade] = new Shader("shaders/fade.vert", "shaders/fade.frag");
	registry[Mandelbrot] = new Shader("shaders/fade.vert", "shaders/mandelbrot.frag");
}

void ShadersRegistry::setVPMatrix(const glm::mat4& vp)
{
	registry[Mandelbrot]->setVPMat(vp);
	registry[Fade]->setVPMat(vp);
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


void ShadersRegistry::enable(Shaders shader)
{
	registry[shader]->enable();
}

void ShadersRegistry::disable(Shaders shader)
{
	registry[shader]->disable();
}

Shader* ShadersRegistry::get(Shaders shader)
{
	return registry[shader];
}
