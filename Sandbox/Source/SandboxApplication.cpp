#include <LGE.h>

class SandboxApplication : public LGE::Application 
{
public:
	SandboxApplication()
	{

	}

	~SandboxApplication()
	{

	}
};

LGE::Application* LGE::CreateApplication() 
{
	return new SandboxApplication();
}
