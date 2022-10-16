#include "ShadersRegistry.h"

#include "../utils/Debug.h";

ShadersRegistry::ShadersRegistry() = default;

void ShadersRegistry::loadAll()
{
	Debug::log("Loading all shaders...");

	registry[Shaders::Basic] = new Shader("shaders/basic.vert", "shaders/basic.frag");
	registry[Shaders::Fade] = new Shader("shaders/fade.vert", "shaders/fade.frag");
	registry[Shaders::Mandelbrot] = new Shader("shaders/fade.vert", "shaders/mandelbrot.frag");
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