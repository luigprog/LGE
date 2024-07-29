#include "Application.h"

#include <iostream>

#include <glad/glad.h>

#include "Window.h"

namespace LGE 
{
    Application* Application::s_Instance = nullptr;

	Application::Application() 
        : m_Window(nullptr), m_ActiveScene(nullptr)
	{
        // TODO: Assert there is only one instance of Application
        s_Instance = this;

        m_Window = new Window();
	}

	Application::~Application()
	{
        delete m_ActiveScene;

        delete m_Window;
	}

    void Application::ActivateScene(Scene* scene)
    {
        m_ActiveScene = scene;
        m_ActiveScene->OnActivate();
    }

	void Application::Run()
	{
        float time = m_Window->GetTime();

        while (!m_Window->ShouldClose())
        {
            float nowTime = m_Window->GetTime();
            float deltaTime = nowTime - time;
            time = nowTime;

            if (m_ActiveScene != nullptr)
            {
                m_ActiveScene->Update(deltaTime);
            }

            /* Render here */
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            if (m_ActiveScene != nullptr)
            {
                m_ActiveScene->Render();
            }

            m_Window->Update();
        }
	}
}
