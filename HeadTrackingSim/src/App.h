#pragma once

#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>

#include "Input.h"
#include "gui/Gui.h"
#include "world/World.h"

class App
{
private:
	App();
	~App();
	static App* instance;
public:
	void loop();
	int getWidth() const;
	int getHeight() const;
	const World* getWorld() const;
	bool isRunning() const;
	glm::vec3 configTranslation = { 0.0f, 0.0f, -7.0f };
	glm::vec3 configMultiplier = { 0.01f, 0.01f, 0.01f };
	glm::vec3 udpVector = { 0.0f, 0.0f, 0.0f };
	nlohmann::json getConfigJson();
private:
	GLFWwindow* window;
	void update();
	void render();
	bool running;
	int width;
	int height;
	Input* input;
	Gui gui;
	World world;
	double frameCap;
public:
	static App* create();
	static App* getInstance();
	static void terminate();
	static void frameBufferResize(GLFWwindow* window, int width, int height);
	static void invokeInput(GLFWwindow* window, int key, int scancode, int action, int mods);
};
