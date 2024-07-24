#pragma once

#include "Core.h"

#include "Scene.h"

#include <stdint.h>

struct GLFWwindow;

namespace LGE
{
	const uint32_t k_ScreenWidth = 1280;
	const uint32_t k_ScreenHeight = 720;

	class LGE_API Application
	{
	private:
		GLFWwindow* m_Window;
		Scene* m_ActiveScene;
	public:
		Application();
		virtual ~Application();
		void ActivateScene(Scene* scene);
		void Run();
	private:
		bool InitializeGlfw();
		bool CreateWindow();
		bool InitializeGl();
	};

	// To be defined in client application
	Application* CreateApplication();
}
