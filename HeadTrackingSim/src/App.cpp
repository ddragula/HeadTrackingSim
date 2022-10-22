#include <glad/glad.h>
#include "App.h"

#include "utils/Debug.h"
#include "registry/ShadersRegistry.h"

#ifdef _WIN32
#include <windows.h>
#define delay(ms) Sleep(ms)
#else
#include <unistd.h>
#define delay(ms) usleep(ms * 1000)
#endif

App* App::instance = nullptr;

App::App() : running(true), width(800), height(600), frameCap(0)
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

	ShadersRegistry::loadAll();
	gui.initialize(window);
	world.start();
}

void App::loop()
{
	double lastFrame = glfwGetTime();

	while (running)
	{
		const double now = glfwGetTime();
		const double frameTime = now - lastFrame;
		lastFrame = now;

		update(frameTime);
		render();

		if (glfwWindowShouldClose(window))
		{
			running = false;
			break;
		}

		if (frameCap > 0.0f && frameTime < frameCap)
		{
			delay(static_cast<unsigned long>((frameCap - frameTime) * 1000.0));
		}
	}
}

void App::update(double deltaTime)
{
	glfwPollEvents();

	gui.update();
	world.update(deltaTime);
}

void App::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

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
