#include <glad/glad.h>
#include "App.h"

#include "utils/Debug.h"

App* App::instance = nullptr;

unsigned int VBO, VAO;

App::App() : running(true), width(800), height(600)
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

	shaders.loadAll();
	gui.initialize(window);

	// ----------------- TEST -------------------

	float vertices[] = {
		-1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,

		 1.0f,  1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// -----------------------------------------------
}

void App::loop()
{
	while (running)
	{
		update();
		render();

		if (glfwWindowShouldClose(window))
		{
			running = false;
			break;
		}
	}
}

void App::update()
{
	glfwPollEvents();

	gui.update();
}

void App::render()
{

	// render
// ------
	glClear(GL_COLOR_BUFFER_BIT);

	// draw our first triangle
	shaders.enable("mandelbrot");
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glDrawArrays(GL_TRIANGLES, 0, 6); // set the count to 6 since we're drawing 6 vertices now (2 triangles); not 3!
	// glBindVertexArray(0); // no need to unbind it every time 

	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	// -------------------------------------------------------------------------------

	gui.render();

	glfwSwapBuffers(window);
}

App::~App()
{
	gui.terminate();
	shaders.unloadAll();

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
}

void App::invokeInput(GLFWwindow* window, const int key, const int scancode, const int action, const int mods)
{
	getInstance()->input->setKeyState(key, action != GLFW_RELEASE);
	Debug::log(std::to_string((int)window) + " " + std::to_string(key) + " " + std::to_string(scancode) + " " + std::to_string(action) + " " + std::to_string(mods));
}
