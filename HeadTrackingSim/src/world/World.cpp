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

	mandelbrotPlane = new Plane("plane", { 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f });
	mandelbrotPlane->setShader(ShadersRegistry::get("color"));
	
	crosshair = new Crosshair();
}

void World::update()
{

}

void World::render() const
{
	// ========= PERSPECTIVE =========
	camera->setMode(Camera::Perspective);
	ShadersRegistry::get("color")->setUniform3f("color", { 1.0f, 0.0f, 1.0f });

	mandelbrotPlane->render();

	
	// ==== FIXED ORTOGRAPHIC UI =====
	camera->setMode(Camera::UIMode);
	ShadersRegistry::get("color")->setUniform3f("color", { 0.0f, 1.0f, 0.0f });

	crosshair->render();
}

void World::truncate()
{

}

Camera* World::getCamera() const
{
	return camera;
}
