#pragma once

#include "Core.h"
#include "Scene.h"

namespace LGE
{
	class Window;

	const unsigned int k_ScreenWidth = 1280;
	const unsigned int k_ScreenHeight = 720;

	class LGE_API Application
	{
	private:
		Window* m_Window;
		Scene* m_ActiveScene;
	private:
		static Application* s_Instance;
	public:
		Application();
		virtual ~Application();
		void ActivateScene(Scene* scene);
		void Run();
		static Application& Get() { return *s_Instance; }
	};

	// To be defined in client application
	Application* CreateApplication();
}
