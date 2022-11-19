#include "TestGuiWindow.h"

#include <imgui/imgui.h>
#include <string>
#include "../Time.h"
#include "../utils/Debug.h"

TestGuiWindow::TestGuiWindow() : GuiWindow()
{
}

void TestGuiWindow::update()
{
	if (show)
	{
		ImGui::Begin("Test Window", &show);
		ImGui::Text("Hello from test window!");

		int fps = 1.0 / Time::deltaTime();

		ImGui::Text(std::string(std::string("FPS: ") + std::to_string(fps)).c_str());
		if (ImGui::Button("Close Me"))
			show = false;
		ImGui::End();
	}
}