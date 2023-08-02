#include "CameraWindow.h"

#include <fstream>
#include "../App.h"
#include "../utils/Debug.h"

CameraWindow::CameraWindow()
{
}

void CameraWindow::update()
{
	const auto app = App::getInstance();

	if (show)
	{
		ImGui::Begin("Camera Translation Configuration", &show);
		ImGui::Text("Position Displacement:");
		ImGui::SliderFloat("tx", &app->configTranslation.x, -10.0f, 10.0f);
		ImGui::SliderFloat("ty", &app->configTranslation.y, -10.0f, 10.0f);
		ImGui::SliderFloat("tz", &app->configTranslation.z, -20.0f, 20.0f);
		ImGui::Text("Position Scale Multiplier:");
		ImGui::SliderFloat("mx", &app->configMultiplier.x, 0.05f, 0.001f);
		ImGui::SliderFloat("my", &app->configMultiplier.y, 0.05f, 0.001f);
		ImGui::SliderFloat("mz", &app->configMultiplier.z, 0.05f, 0.001f);

		if (ImGui::Button("Reset Configuration")) {
			app->configTranslation.x = 0.0f;
			app->configTranslation.y = 0.0f;
			app->configTranslation.z = -7.0f;
			app->configMultiplier.x = 0.01f;
			app->configMultiplier.y = 0.01f;
			app->configMultiplier.z = 0.01f;
		}

		if (ImGui::Button("Save Configuration")) {
			auto textJson = nlohmann::to_string(app->getConfigJson());
			std::ofstream oFile("config.json");
			if (oFile.is_open()) {
				oFile.write(textJson.c_str(), textJson.length());
			}
			oFile.close();
			Debug::log("Config file saved as 'config.json'");
		}
		ImGui::End();
	}
}
