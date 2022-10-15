#include "Shaders.h"

#include "../utils/Debug.h";

Shaders::Shaders() = default;

void Shaders::loadAll()
{
	Debug::log("Loading all shaders...");

	registry["basic"] = new Shader("shaders/basic.vert", "shaders/basic.frag");
	registry["fade"] = new Shader("shaders/fade.vert", "shaders/fade.frag");
	registry["mandelbrot"] = new Shader("shaders/fade.vert", "shaders/mandelbrot.frag");
}

void Shaders::unloadAll()
{
	for (auto &record: registry)
	{
		Debug::log("Shader '" + record.first + "' has been unloaded");
		delete record.second;
		record.second = nullptr;
	}
}


void Shaders::enable(const std::string& id)
{
	registry[id]->enable();
}

void Shaders::disable(const std::string& id)
{
	registry[id]->disable();
}
