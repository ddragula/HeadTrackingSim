#include "World.h"

#include "../registry/ShadersRegistry.h"
#include "../utils/Debug.h"
#include "../Time.h"

World::World() = default;

void World::start()
{
	srand(time(0));

	udp = new UDPReceiver(8080);

	camera = new Camera("Camera");
	camera->setPosition({ 0.0f, 0.0f, 2.0f });

	crosshair = new Crosshair();
	crosshair->setColor({ 1.0f, 1.0f, 1.0f });

	circles = new Object("Circles");
	for (int i = 0; i < 10; i++) {
		auto circle = new RegularPolygon("Circle" + std::to_string(i), { 0.0f, 0.0f, -i * 2.0f }, { 0.0f, 0.0f, 0.0f }, 32, 1.0f);
		circle->setColor({ i > 4 ? 1.0f : i * 0.2f, i < 5 ? (i + 1) * 0.2f : 1.0f - (i - 4) * 0.2f, 0});
		circles->addChild(circle);
	}

	aim = new RegularPolygon("Aim", { 0.0f, 0.0f, -20.0f }, { 0.0f, 0.0f, 0.0f }, 8, 0.1f);
	aim->setColor({ 1.0f, 0.0f, 0.0f });

	preAim = new RegularPolygon("PreAim", { 0.0f, 0.0f, -10.0f }, { 0.0f, 0.0f, 0.0f }, 16, 0.1f);
	preAim->setColor({ 1.0f, 1.0f, 0.0f });

	cubes = new Object("Cubes");
	for (int i = 0; i < 30; i++) {
		auto cube = new Cube("Cube" + std::to_string(i), { 0.5f, 0.5f, 0.5f }, { rand() % 40 - 20, rand() % 40 - 20, -rand() % 20 - 20 });
		cube->setShader(ShadersRegistry::get(rand() % 2 ? "mandelbrot" : "fade"));
		cubes->addChild(cube);
	}
	enableCubes = new bool(false);
}

void World::update()
{
	glm::vec3 rawCamPos = udp->receivePositionVector(); // TODO: move it to new thread.
	float x = rawCamPos.x / 100.0f;
	float y = rawCamPos.y / 100.0f;
	float z = (rawCamPos.z - 700.0f) / 100.0f;

	camera->setPosition(glm::vec3(-x, -y, z));

	cubes->setEnabled(*enableCubes);
}

void World::render() const
{
	// ========= PERSPECTIVE =========
	camera->setMode(Camera::Perspective);
	aim->render();
	preAim->render();
	circles->render();
	cubes->render();
	
	// ==== FIXED ORTOGRAPHIC UI =====
	camera->setMode(Camera::UIMode);
	crosshair->render();
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
