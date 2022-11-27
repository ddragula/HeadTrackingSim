#include "Menu.h"

#include "imgui/imgui.h"
#include "../utils/Debug.h"

Menu::Menu() : showTestWindow(nullptr)
{
}

void Menu::initialize(bool* showTestWindow, bool* showCameraWindow)
{
    this->showTestWindow = showTestWindow;
    this->showCameraWindow = showCameraWindow;
}

void Menu::update()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Test Window", nullptr, showTestWindow)) {}
            if (ImGui::MenuItem("Camera", nullptr, showCameraWindow)) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void Menu::terminate()
{

}
