#include "Application.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace LGE 
{
	Application::Application() 
        : m_Window(nullptr), m_ActiveScene(nullptr)
	{
        InitializeGlfw();

        CreateWindow();

        InitializeGl();
	}

	Application::~Application()
	{
        delete m_ActiveScene;

        glfwDestroyWindow(m_Window);
        glfwTerminate();
	}

    bool Application::InitializeGlfw()
    {
        if (!glfwInit())
        {
            std::cout << "ERROR: Failed initializing GLFW." << std::endl;
            return false;
        }

        return true;
    }

    bool Application::CreateWindow()
    {
        if (m_Window)
        {
            std::cout << "ERROR: An instance of window already exists." << std::endl;
            return false;
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Window = glfwCreateWindow(k_ScreenWidth, k_ScreenHeight, "LGE", NULL, NULL);

        if (!m_Window)
        {
            std::cout << "ERROR: Failed creating GLFW window." << std::endl;
            glfwTerminate();
            return false;
        }

        return true;
    }

    bool Application::InitializeGl()
    {
        glfwMakeContextCurrent(m_Window);

        // glad: load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
            return false;
        }

        glfwSwapInterval(1); // Enable vsync

        std::cout << glGetString(GL_VERSION) << std::endl;

        glViewport(0, 0, k_ScreenWidth, k_ScreenHeight);

        return true;
    }

    void Application::ActivateScene(Scene* scene)
    {
        m_ActiveScene = scene;
        m_ActiveScene->OnActivate();
    }

	void Application::Run()
	{
        float time = glfwGetTime();

        while (!glfwWindowShouldClose(m_Window))
        {
            glfwPollEvents();

            float nowTime = glfwGetTime();
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

            glfwSwapBuffers(m_Window);
        }
	}
}
