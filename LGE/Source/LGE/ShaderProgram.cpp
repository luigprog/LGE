#include "ShaderProgram.h"

#include <iostream>

#include "glad/glad.h"

namespace LGE
{
	ShaderProgram::ShaderProgram(const char* vertexShaderSrc, const char* fragmentShaderSrc)
		: m_Id(0)
	{
		m_Id = CreateShader(vertexShaderSrc, fragmentShaderSrc);
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_Id);
	}

	void ShaderProgram::Bind() const
	{
		glUseProgram(m_Id);
	}

	void ShaderProgram::Unbind() const
	{
		glUseProgram(0);
	}

	void ShaderProgram::SetUniform1i(const std::string& name, int32_t v)
	{
		glUniform1i(GetUniformLocation(name), v);
	}

	void ShaderProgram::SetUniform1f(const std::string& name, float v)
	{
		glUniform1f(GetUniformLocation(name), v);
	}

	void ShaderProgram::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
	}

	uint32_t ShaderProgram::CreateShader(const char* vertexShaderSrc, const char* fragmentShaderSrc)
	{
		uint32_t program = glCreateProgram();
		uint32_t vs = CompileShader(GL_VERTEX_SHADER, vertexShaderSrc);
		uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSrc);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}

	uint32_t ShaderProgram::CompileShader(uint32_t type, const char* src)
	{
		uint32_t id = glCreateShader(type);
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

	int ShaderProgram::GetUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) == m_UniformLocationCache.end())
		{
			m_UniformLocationCache[name] = glGetUniformLocation(m_Id, name.c_str());
		}

		return m_UniformLocationCache.at(name);
	}
}
