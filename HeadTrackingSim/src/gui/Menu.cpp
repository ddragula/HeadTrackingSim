#include "Menu.h"

#include "imgui/imgui.h"
#include "../utils/Debug.h"

Menu::Menu() : showTestWindow(nullptr)
{
}

void Menu::initialize(bool* showTestWindow)
{
    this->showTestWindow = showTestWindow;
}

void Menu::update()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Test Window", nullptr, showTestWindow)) {}
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void Menu::terminate()
{

}
