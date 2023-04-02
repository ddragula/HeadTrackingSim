#include "Menu.h"

#include "imgui/imgui.h"
#include "../utils/Debug.h"
#include "../App.h"

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
        if (ImGui::BeginMenu("Menu"))
        {
            if (ImGui::MenuItem("Test Window", nullptr, showTestWindow)) {}
            if (ImGui::MenuItem("Camera", nullptr, showCameraWindow)) {}
            if (ImGui::MenuItem("Cubes", nullptr, App::getInstance()->getWorld()->enableCubes)) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void Menu::terminate()
{

}
