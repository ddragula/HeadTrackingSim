#include "World.h"

#include "../registry/ShadersRegistry.h";

World::World() = default;

void World::start()
{
	mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get(Shaders::Mandelbrot));
}

void World::update()
{
}

void World::render()
{
	mandelbrotPlane->render();
}

void World::truncate()
{
	delete mandelbrotPlane;
	mandelbrotPlane = nullptr;
}
