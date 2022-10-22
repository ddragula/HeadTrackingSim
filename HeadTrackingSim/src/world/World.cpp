#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"

World::World() = default;

void World::start()
{
	camera = new Camera("Camera");
	camera->setPosition({ 0.0f, 0.0f, 3.0f });
	camera->setMode(Camera::Perspective);

	mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.0f, 1.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get(ShadersRegistry::Mandelbrot));
}

void World::update(const double deltaTime)
{
	mandelbrotPlane->rotate({ 0, 100 * deltaTime, 0 });
	mandelbrotPlane->translate({ 0, 0, -deltaTime });
}

void World::render() const
{
	camera->render();
	mandelbrotPlane->render();
}

void World::truncate()
{

}
