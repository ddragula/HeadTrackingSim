#pragma once

#include <GLFW/glfw3.h>

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
public:
	static App* create();
	static App* getInstance();
	static void terminate();
	static void frameBufferResize(GLFWwindow* window, int width, int height);
	static void invokeInput(GLFWwindow* window, int key, int scancode, int action, int mods);
};
