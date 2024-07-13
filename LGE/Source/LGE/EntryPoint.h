#pragma once

#ifdef LGE_PLATFORM_WINDOWS

extern LGE::Application* LGE::CreateApplication();

int main(int argc, char** argv) 
{
	auto app = LGE::CreateApplication();
	app->Run();
	delete app;
}

#endif
