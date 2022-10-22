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

void World::update(double deltaTime)
{
	static unsigned int n = 0;
	static double time = 0;
	mandelbrotPlane->rotate({ 0.0f, 0.05f, 0.0f });
	parent->rotate({ 0.0f, 0.0f, 0.05f });

	if ((int)time != (int)(time + deltaTime))
	{
		Debug::log(std::to_string(n));
		n = 0;
	}

	time += deltaTime;
	n++;
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
