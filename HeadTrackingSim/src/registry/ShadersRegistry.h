#pragma once

#include <unordered_map>
#include <string>

#include "../graphics/Shader.h"

enum Shaders {
	Basic,
	Fade,
	Mandelbrot
};

class ShadersRegistry
{
public:
	ShadersRegistry();

	void loadAll();
	void unloadAll();
	void enable(Shaders shader);
	void disable(Shaders shader);
	Shader* get(Shaders shader);
private:
	std::unordered_map<Shaders, Shader*> registry;
};
