#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"
#include "../Time.h"

World::World() = default;

void World::start()
{
	srand(time(0));

	camera = new Camera("Camera");
	camera->setPosition({ 0.0f, 0.0f, 2.5f });

	circles = new Object("Camera Parent", { 0, 0, 0 }, { 0, 0, 0 });
	circles->addChild(camera);

	mandelbrot = new Cube("Mandelbrot", { 1, 1, 1 }, { 0, 0, 0 });
	mandelbrot->setShader(ShadersRegistry::get("mandelbrot"));
	mandelbrot->rotate({ 20.2f, 4.5f, 10.0f });

	enableCubes = new bool(false);
}

void World::update()
{
	circles->rotate({ 0, 0.1f, 0 });
}

void World::render() const
{
	circles->render();
	mandelbrot->render();
}

void World::truncate()
{
	delete circles;
	delete crosshair;
	delete camera;
	delete enableCubes;
}

Camera* World::getCamera() const
{
	return camera;
}
