#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"

World::World() = default;

void World::start()
{
	camera = new Camera("Camera");
	camera->setPosition({ 0.0f, 0.0f, 3.0f });
	camera->setMode(Camera::Perspective);

	parent = new Object("Empty Object");
	parent->setPosition({ 1.0f, 0.0f, 0.0f });

	mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.0f, 1.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get(Shaders::Mandelbrot));

	parent->addChild(mandelbrotPlane);
}

void World::update()
{
	mandelbrotPlane->rotate({ 0.0f, 0.05f, 0.0f });
	parent->rotate({ 0.0f, 0.0f, 0.05f });
}

void World::render() const
{
	camera->render();
	parent->render();
}

void World::truncate()
{
	delete mandelbrotPlane;
	mandelbrotPlane = nullptr;
}
