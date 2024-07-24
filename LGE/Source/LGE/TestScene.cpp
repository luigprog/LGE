#include "TestScene.h"

#include "Shader.h"

#include <iostream>

#include <glad/glad.h>

namespace LGE
{
	TestScene::TestScene() 
	{
		std::cout << "TestScene()" << std::endl;
	}

	TestScene::~TestScene()
	{
		std::cout << "~TestScene()" << std::endl;
	}

	void TestScene::OnActivate()
	{
		std::cout << "TestScene OnActivate()" << std::endl;

		uint32_t vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		float vertices[] =
		{
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//

		std::string vertexShaderSrc =
			"#version 330 core\n"
			"\n"
			"layout(location = 0) in vec4 position;\n"
			"\n"
			"void main()\n"
			"{\n"
			"    gl_Position = position;\n"
			"}\n";

		std::string fragmentShaderSrc =
			"#version 330 core\n"
			"\n"
			"layout(location = 0) out vec4 color;\n"
			"\n"
			"void main()\n"
			"{\n"
			"    color = vec4(1.0, 0.0, 0.0, 1.0);\n"
			"}\n";

		Shader shader(vertexShaderSrc, fragmentShaderSrc);
		shader.Bind();
	}
	
	void TestScene::Update(float deltaTime)
	{
	}

	void TestScene::Render() const
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}