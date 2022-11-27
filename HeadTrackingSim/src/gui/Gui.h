#pragma once

#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui.h>

#include "Menu.h"
#include "TestGuiWindow.h"
#include "CameraWindow.h"

class Gui
{
public:
	Gui();
	void initialize(GLFWwindow* window);
	void terminate();
private:
	ImGuiIO* io;
	Menu menu;
	TestGuiWindow testWindow;
	CameraWindow cameraWindow;
public:
	void update();
	void render();
};
