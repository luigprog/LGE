#include <iostream>

#include <LGE.h>

class SandboxApplication : public LGE::Application 
{
private:
	LGE::TestScene* m_TestScene = nullptr;

public:
	SandboxApplication()
	{
		std::cout << "SandboxApplication()" << std::endl;

		m_TestScene = new LGE::TestScene();
		ActivateScene(m_TestScene);
	}

	~SandboxApplication()
	{
		delete m_TestScene;
		
		std::cout << "~SandboxApplication()}" << std::endl;
	}
};

LGE::Application* LGE::CreateApplication() 
{
	return new SandboxApplication();
}
