#pragma once

#include <string>
#include <unordered_map>

namespace LGE
{
    // A ShaderProgram is composed of a vertex and a fragment shader
    class ShaderProgram
    {
    private:
        uint32_t m_Id; // Shader Program id
        std::unordered_map<std::string, int> m_UniformLocationCache;
    public:
        ShaderProgram(const char* vertexShaderSrc, const char* fragmentShaderSrc);
        ~ShaderProgram();

        void Bind() const;
        void Unbind() const;

        // Set uniforms
        void SetUniform1i(const std::string& name, int v);
        void SetUniform1f(const std::string& name, float v);
        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    private:
        uint32_t CreateShader(const char* vertexShaderSrc, const char* fragmentShaderSrc);
        uint32_t CompileShader(uint32_t type, const char* src);

        int GetUniformLocation(const std::string& name);
    };
}
