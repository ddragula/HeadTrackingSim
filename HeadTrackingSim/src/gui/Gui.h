#pragma once

#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui.h>

class Gui
{
public:
	Gui();
	void initialize(GLFWwindow* window);
	void terminate();
private:
	ImGuiIO* io;
	GLFWwindow* window;
public:
	void newFrame();
	void render();
};