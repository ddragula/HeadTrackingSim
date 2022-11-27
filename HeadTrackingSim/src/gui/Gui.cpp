#include "Gui.h"

#include <imgui/imgui_impl_opengl3.h>
#include "../utils/Debug.h"

Gui::Gui() : io(nullptr)
{
}

void Gui::initialize(GLFWwindow * window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO();

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");

	testWindow.initialize(false);
	cameraWindow.initialize(false);
    menu.initialize(&testWindow.show, &cameraWindow.show);
}

void Gui::update()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	testWindow.update();
	cameraWindow.update();
	menu.update();

    ImGui::Render();
}

void Gui::render()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Gui::terminate()
{
	menu.terminate();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
