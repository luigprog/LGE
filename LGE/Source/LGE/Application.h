#pragma once

#include "Core.h"

namespace LGE
{

	class LGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client application
	Application* CreateApplication();

}
