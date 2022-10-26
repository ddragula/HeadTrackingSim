#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"

World::World() = default;

void World::start()
{
	camera = new Camera("Camera");
	camera->setMode(Camera::Perspective);
	camera->setPosition({ 0.0f, 0.0f, 2.0f });

	parent = new Object("Parent");
	parent->addChild(camera);

	mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.5f, 1.5f });
	mandelbrotPlane->setShader(ShadersRegistry::get(ShadersRegistry::Mandelbrot));
}

void World::update(const double deltaTime)
{
	parent->rotate({ 0.0f, 0.3f, 0.0f });
}

void World::render() const
{
	parent->render();
	mandelbrotPlane->render();
}

void World::truncate()
{

}
