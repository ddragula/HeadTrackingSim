#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"
#include "../Time.h"

World::World() = default;

void World::start()
{
	camera = new Camera("Camera");
	camera->setMode(Camera::Perspective);
	camera->setPosition({ 0.0f, 0.0f, 2.0f });

	parent = new Object("Parent");
	parent->addChild(camera);

	farPlane = new Plane("Far Plane", { 1.0f, 1.0f });
	farPlane->setShader(ShadersRegistry::get(ShadersRegistry::Mandelbrot));
	farPlane->rotate({ 0.0f, 45.0f, 0.0f });

	mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.0f, 1.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get(ShadersRegistry::Mandelbrot));
}

void World::update()
{
	parent->rotate({ 0.0f, 30.0f * Time::deltaTime(), 0.0f });
}

void World::render() const
{
	parent->render();
	farPlane->render();
	mandelbrotPlane->render();
}

void World::truncate()
{

}
