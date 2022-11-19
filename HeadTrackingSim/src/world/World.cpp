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

	farPlane = new Plane("Far Plane", { 1.0f, 1.0f });
	farPlane->setShader(ShadersRegistry::get(ShadersRegistry::Fade));
	farPlane->rotate({ 0.0f, 90.0f, 0.0f });

	mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.0f, 1.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get(ShadersRegistry::Mandelbrot));

	parent = new Object("Parent");
	parent->addChild(farPlane);
	parent->addChild(mandelbrotPlane);
}

void World::update()
{
	parent->rotate({ 0.0f, 90.0f * Time::deltaTime(), 0.0f });
}

void World::render() const
{
	camera->render();
	parent->render();
}

void World::truncate()
{

}
