#include "CameraWindow.h"

#include "../App.h"

CameraWindow::CameraWindow()
{
}

void CameraWindow::update()
{
	if (!camera)
	{
		camera = App::getInstance()->getWorld()->getCamera();
		const auto position = camera->getPosition();
		pos_x = position.x;
		pos_y = position.y;
		pos_z = position.z;

		const auto rotation = camera->getRotation();
		rot_x = rotation.x;
		rot_y = rotation.y;
		rot_z = rotation.z;
	}

	if (show)
	{
		ImGui::Begin("Camera", &show);
		ImGui::Text("Position:");
		ImGui::SliderFloat("x", &pos_x, -10.0f, 10.0f);
		ImGui::SliderFloat("y", &pos_y, -10.0f, 10.0f);
		ImGui::SliderFloat("z", &pos_z, -10.0f, 10.0f);
		ImGui::Text("Rotation:");
		ImGui::SliderFloat("rx", &rot_x, -180.0f, 180.0f);
		ImGui::SliderFloat("ry", &rot_y, -180.0f, 180.0f);
		ImGui::SliderFloat("rz", &rot_z, -180.0f, 180.0f);
		if (ImGui::Button("Reset Position")) {
			rot_x = 0.0f;
			rot_y = 0.0f;
			rot_z = 0.0f;
			pos_x = 0.0f;
			pos_y = 0.0f;
			pos_z = 2.0f;
		}
		ImGui::End();

		camera->setRotation({ rot_x, rot_y, rot_z });
		camera->setPosition({ pos_x, pos_y, pos_z });
	}
}
