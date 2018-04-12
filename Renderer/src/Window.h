#pragma once

class GLFWwindow;

class Window
{
public:
	Window();
	~Window();

	bool Init();

	void SwapBuffers();
	bool ShouldWindowClose();
private:
	GLFWwindow* m_pGLFWWindow;
};
