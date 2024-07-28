#include <iostream>

#include <LGE.h>

class SandboxApplication : public LGE::Application 
{
public:
	SandboxApplication()
	{
		std::cout << "SandboxApplication()" << std::endl;

		ActivateScene(new LGE::TestScene());
	}

	~SandboxApplication()
	{
		std::cout << "~SandboxApplication()" << std::endl;
	}
};

LGE::Application* LGE::CreateApplication() 
{
	return new SandboxApplication();
}
