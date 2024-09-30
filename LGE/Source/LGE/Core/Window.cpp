#include "Window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace LGE 
{
	Window::Window(const std::string& title, unsigned int width, unsigned int height)
		: m_GlfwWindow(nullptr)
	{
		// Initialize Glfw
		if (!glfwInit())
		{
			std::cout << "ERROR: Failed initializing GLFW." << std::endl;
			return;
		}

		// Create Window
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_GlfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

		if (!m_GlfwWindow)
		{
			std::cout << "ERROR: Failed creating GLFW window." << std::endl;
			glfwTerminate();
			return;
		}

		// Initialize Gl Context
		glfwMakeContextCurrent(m_GlfwWindow);

		// glad: load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
			return;
		}

		glfwSwapInterval(1); // Enable vsync

		std::cout << glGetString(GL_VERSION) << std::endl;

		glViewport(0, 0, width, height);
	}
	
	Window::~Window()
	{
		glfwDestroyWindow(m_GlfwWindow);
		glfwTerminate();
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_GlfwWindow);
	}

	float Window::GetTime() const
	{
		return static_cast<float>(glfwGetTime());
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_GlfwWindow);
	}
}