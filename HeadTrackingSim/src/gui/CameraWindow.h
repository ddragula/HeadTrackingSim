#pragma once

#include "GuiWindow.h"
#include "../graphics/objects/Camera.h"

class CameraWindow : public GuiWindow
{
public:
	CameraWindow();
	void update() override;
private:
	Camera* camera;
	float tra_x, tra_y, tra_z;
	float mul_x, mul_y, mul_z;
};