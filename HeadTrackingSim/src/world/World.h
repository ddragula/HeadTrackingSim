#pragma once

#include "../graphics/objects/Camera.h"
#include "../graphics/objects/models/models.h";

class World
{
public:
	World();

	void start();
	void update();
	void render() const;
	void truncate();
private:
	Plane* mandelbrotPlane;
	Camera* camera;
	Object* parent;
};