#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"
#include "../Time.h"

World::World() = default;

void World::start()
{
	srand(time(0));

	camera = new Camera("Camera");
	{
		camera->setMode(Camera::Perspective);
		camera->setPosition({ 0.0f, 0.0f, 2.0f });
	}

	parent = new Object("Parent");
	{
		fadePlane = new Plane("Fade Plane", { 1.0f, 1.0f });
		fadePlane->setShader(ShadersRegistry::get(ShadersRegistry::Fade));
		fadePlane->rotate({ 0.0f, 90.0f, 0.0f });

		mandelbrotPlane = new Plane("Mandelbrot Plane", { 1.0f, 1.0f });
		mandelbrotPlane->setShader(ShadersRegistry::get(ShadersRegistry::Mandelbrot));

		parent->addChild(fadePlane);
		parent->addChild(mandelbrotPlane);
	}
	
	for (int i = 0; i < 30; i++)
	{
		const auto cube = new Cube("Cube", {1.0f, 1.0f, 1.0f });
		cube->setPosition({ float(rand() % 6) - 3.0f, float(rand() % 6) - 3.0f, float(rand() % 44) - 13.0f });
		cube->setShader(ShadersRegistry::get(i % 2 ? ShadersRegistry::Mandelbrot : ShadersRegistry::Fade));
		cubes.push_back(cube);
	}
}

void World::update()
{
	parent->rotate({ 0.0f, 90.0f * Time::deltaTime(), 0.0f });

	for (int i = 0; i < 30; i++)
	{
		cubes[i]->rotate({0.0f, float(i - 15) * 30.0f * Time::deltaTime(), 0.0f});
	}
}

void World::render() const
{
	camera->render();

	for (const auto cube : cubes)
	{
		cube->render();
	}
}

void World::truncate()
{

}

Camera* World::getCamera() const
{
	return camera;
}
