#include "Window.h"
#include "Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	glewExperimental = GL_TRUE;

	Window window;

	if (!glfwInit())
	{
		return -1;
	}

	if (!window.Init())
	{
		glfwTerminate();
		return -1;
	}

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error..." << std::endl;
	}

	glViewport(0, 0, 800, 600);

	Shader shader("res/shaders/shader.vert", "res/shaders/shader.frag");

	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	while (!window.ShouldWindowClose())
	{
		// process input
		glClearColor(0.04, 0.04, 0.04, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Check call events and swap buffers
		window.SwapBuffers();
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
