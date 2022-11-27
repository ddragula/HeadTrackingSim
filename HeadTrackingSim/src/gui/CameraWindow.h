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
	float pos_x, pos_y, pos_z;
	float rot_x, rot_y, rot_z;
};