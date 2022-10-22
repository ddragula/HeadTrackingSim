#pragma once

#include <unordered_map>
#include <string>

#include "../graphics/Shader.h"

class ShadersRegistry
{
public:
	enum Shaders {
		Basic,
		Fade,
		Mandelbrot
	};
private:
	ShadersRegistry() = delete;
public:
	static void loadAll();
	static void unloadAll();
	static void enable(Shaders shader);
	static void disable(Shaders shader);
	static Shader* get(Shaders shader);
	static void setVPMatrix(const glm::mat4& vp);
private:
	static std::unordered_map<Shaders, Shader*> registry;
};
