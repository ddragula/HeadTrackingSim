#pragma once

#include "../graphics/models/models.h";

class World
{
public:
	World();

	void start();
	void update();
	void render();
	void truncate();
private:
	Plane* mandelbrotPlane;
};