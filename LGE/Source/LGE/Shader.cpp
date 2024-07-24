#include "Shader.h"

#include <iostream>

#include "glad/glad.h"

namespace LGE
{
	Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
		: m_Id(0)
	{
		m_Id = CreateShader(vertexSource, fragmentSource);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_Id);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_Id);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform1i(const std::string& name, int32_t v)
	{
		glUniform1i(GetUniformLocation(name), v);
	}

	void Shader::SetUniform1f(const std::string& name, float v)
	{
		glUniform1f(GetUniformLocation(name), v);
	}

	void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
	}

	uint32_t Shader::CompileShader(uint32_t type, const std::string& source)
	{
		uint32_t id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "Failed to compile "
				<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
				<< " shader" << std::endl;
			std::cout << message << std::endl;
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	uint32_t Shader::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		uint32_t program = glCreateProgram();
		uint32_t vs = CompileShader(GL_VERTEX_SHADER, vertexSource);
		uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) == m_UniformLocationCache.end())
		{
			m_UniformLocationCache[name] = glGetUniformLocation(m_Id, name.c_str());
		}

		return m_UniformLocationCache.at(name);
	}
}
