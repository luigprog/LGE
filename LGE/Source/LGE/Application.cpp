#include "Application.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace LGE 
{

	Application::Application() 
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            return; //return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return; //return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        // glad: load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
            return; // return -1;
        }

        glfwSwapInterval(1); // Enable vsync

        std::cout << glGetString(GL_VERSION) << std::endl;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
        //return 0;
	}

}
