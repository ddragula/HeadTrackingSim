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
private:
	ShadersRegistry() = delete;
public:
	static void loadAll();
	static void unloadAll();
	static void enable(Shaders shader);
	static void disable(Shaders shader);
	static Shader* get(Shaders shader);
private:
	static std::unordered_map<Shaders, Shader*> registry;
};
