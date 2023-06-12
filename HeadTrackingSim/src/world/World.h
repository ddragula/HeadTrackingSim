#pragma once

#include "../graphics/objects/Camera.h"
#include "../graphics/objects/models/models.h"
#include "../udp/UDPReceiver.h"

#include <vector>

class World
{
public:
	World();

	void start();
	void update();
	void render() const;
	void truncate();

	Camera* getCamera() const;
	bool* enableCubes;
private:
	UDPReceiver* udp;
	Camera* camera;
	Crosshair* crosshair;
	Object* circles;
	RegularPolygon* aim;
	RegularPolygon* preAim;
	Object* cubes;
};