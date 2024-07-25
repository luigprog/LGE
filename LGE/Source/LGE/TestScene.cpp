#include "TestScene.h"

#include "ShaderProgram.h"

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

		// Generate the vertex array object.
		// Bind the VAO so any subsequent vertex attribute calls from that point on will be stored 
		// inside the VAO: vertex buffer data, elements buffer data, attributes layout.
		uint32_t vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		// Generate the vertex buffer object.
		// Set the buffer data on OpenGL.
		uint32_t vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		float vertices[] = {
			// position        // color
		   -0.5f, -0.5f, 0.0f, 1.0, 0.0, 0.0,
			0.5f, -0.5f, 0.0f, 0.0, 1.0, 0.0,
			0.0f,  0.5f, 0.0f, 0.0, 0.0, 1.0
		};
		glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(float), vertices, GL_STATIC_DRAW);

		// Layout/setup vertex attribute pointers
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// Generate the elements buffer object.
		// Set the buffer data on OpenGL.
		uint32_t ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		uint32_t indices[] = {
			0, 1, 2
		};
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(uint32_t), indices, GL_STATIC_DRAW);

		// Unbind VAO and VBO and EBO
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// Bind the VAO to draw
		glBindVertexArray(vao);

		// Shader
		const char* vertexShaderSrc = R"(
			#version 330 core
			
			// attributes
			layout(location = 0) in vec3 aPosition;
			layout(location = 1) in vec3 aColor;

			out vec3 vColor; // color from vertex shader to fragment shader
			
			void main()
			{
				gl_Position = vec4(aPosition, 1.0);
				vColor = aColor;
			}
		)";

		const char* fragmentShaderSrc = R"(
			#version 330 core
			
			out vec4 fColor; // obligatory fragment color output

			in vec3 vColor; // color output from vertex shader
			
			void main()
			{
				fColor = vec4(vColor, 1.0);
			}
		)";

		ShaderProgram shaderProgram(vertexShaderSrc, fragmentShaderSrc);
		shaderProgram.Bind();
	}

	void TestScene::Update(float deltaTime)
	{
	}

	void TestScene::Render() const
	{
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	}
}