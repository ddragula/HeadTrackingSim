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
		camera->setPosition({ 0.0f, 0.0f, 2.0f });
	}

	//mandelbrotPlane = new Plane("plane", { 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f });
	//mandelbrotPlane->setShader(ShadersRegistry::get("mandelbrot"));

	crosshair = new Crosshair();
	crosshair->setColor({ 1.0f, 1.0f, 1.0f });

	polygon = new RegularPolygon("Polygon", { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 6);
	polygon->setEnabled(true);
}

void World::update()
{

}

void World::render() const
{
	// ========= PERSPECTIVE =========
	camera->setMode(Camera::Orthographic);
	polygon->render();

	
	// ==== FIXED ORTOGRAPHIC UI =====
	camera->setMode(Camera::UIMode);
	crosshair->render();
}

void World::truncate()
{

}

Camera* World::getCamera() const
{
	return camera;
}
