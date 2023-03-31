#include <glad/glad.h>
#include "App.h"

#include "utils/Debug.h"
#include "registry/ShadersRegistry.h"
#include "Time.h"

App* App::instance = nullptr;

App::App() : running(true), width(800), height(600), frameCap(1.0 / 60.0), ready(false)
{
	Debug::log("GLFW initialization has started");
	if (!glfwInit())
	{
		Debug::error("GLFW initialization has failed");
		terminate();
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	Debug::log("Creating the window...");
	window = glfwCreateWindow(width, height, "Perspective Simulator", nullptr, nullptr);

	input = new Input();

	if (!window)
	{
		Debug::error("Window creation failed");
		terminate();
		return;
	}

	glfwSetKeyCallback(window, invokeInput);
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBufferResize);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Debug::error("GLAD initialization failed");
		terminate();
		return;
	}

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);

	ShadersRegistry::loadAll();
	gui.initialize(window);
	world.start();
}

void App::loop()
{
	Time::start(glfwGetTime());

	ready = true;
	while (running)
	{
		Time::frame(glfwGetTime());

		update();

		if (width > 0 && height > 0)
		{
			render();
		}

		if (glfwWindowShouldClose(window))
		{
			running = false;
			break;
		}

		Time::frameCap(frameCap);
	}
	ready = false;
}

void App::update()
{
	glfwPollEvents();

	gui.update();
	world.update();
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	world.render();
	gui.render();

	glfwSwapBuffers(window);
}

App::~App()
{
	gui.terminate();
	ShadersRegistry::unloadAll();

	delete input;
	input = nullptr;

	glfwDestroyWindow(window);
	glfwTerminate();
}

App* App::create()
{
	if (!instance)
	{
		instance = new App();
		return instance;
	}
	
	throw std::exception("The application instance has already been created");
}

App* App::getInstance()
{
	return instance;
}

void App::terminate()
{
	delete instance;
	instance = nullptr;
}

int App::getWidth() const
{
	return width;
}

int App::getHeight() const
{
	return height;
}

const World* App::getWorld() const
{
	return &world;
}

void App::frameBufferResize(GLFWwindow* window, const int width, const int height)
{
	const auto appInstance = getInstance();
	appInstance->width = width;
	appInstance->height = height;
	glViewport(0, 0, width, height);
}

void App::invokeInput(GLFWwindow* window, const int key, const int scancode, const int action, const int mods)
{
	getInstance()->input->setKeyState(key, action != GLFW_RELEASE);
	Debug::log(std::to_string((int)window) + " " + std::to_string(key) + " " + std::to_string(scancode) + " " + std::to_string(action) + " " + std::to_string(mods));
}
