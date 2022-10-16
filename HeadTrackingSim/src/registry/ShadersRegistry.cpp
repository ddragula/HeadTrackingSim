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
	for (auto &record: registry)
	{
		Debug::log("Shader (" + std::to_string(record.first) + ") has been unloaded");
		delete record.second;
		record.second = nullptr;
	}
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
