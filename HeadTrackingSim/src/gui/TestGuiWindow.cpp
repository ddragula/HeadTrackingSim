#include "TestGuiWindow.h"

#include <imgui/imgui.h>

TestGuiWindow::TestGuiWindow() : GuiWindow()
{
}

void TestGuiWindow::update()
{
	if (show)
	{
		ImGui::Begin("Test Window", &show);
		ImGui::Text("Hello from test window!");
		if (ImGui::Button("Close Me"))
			show = false;
		ImGui::End();
	}
}