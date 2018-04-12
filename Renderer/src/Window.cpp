#include "Window.h"
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window()
{
}

Window::~Window()
{
}

bool Window::Init()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_pGLFWWindow = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

	if (m_pGLFWWindow == NULL)
	{
		std::cout << "Failed to create GLFW window." << std::endl;
		return false;
	}

	glfwMakeContextCurrent(m_pGLFWWindow);
	return true;
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(m_pGLFWWindow);
}

bool Window::ShouldWindowClose()
{
	return glfwWindowShouldClose(m_pGLFWWindow);
}
