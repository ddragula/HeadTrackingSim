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

	mandelbrotPlane = new Plane("plane", { 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get("mandelbrot"));
}

void World::update()
{


}

void World::render() const
{
	camera->render();
	camera->setMode(Camera::FixedOrtographic);
	mandelbrotPlane->render();
}

void World::truncate()
{

}

Camera* World::getCamera() const
{
	return camera;
}
