#pragma once
 
#include <string>

struct GLFWwindow;

namespace LGE 
{
	class Window 
	{
	private:
		GLFWwindow* m_GlfwWindow;
	public:
		Window(const std::string& title = "Learn Game Engine",
			unsigned int width = 1600,
			unsigned int height = 900);
		~Window();

		GLFWwindow* GetGlfwWindow() { return m_GlfwWindow; }

		bool ShouldClose() const;

		float GetTime() const;

		// Called at the end of the Application run loop
		void Update();
	};
}