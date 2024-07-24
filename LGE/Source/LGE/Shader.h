#pragma once

#include <string>
#include <unordered_map>

namespace LGE
{
    class Shader
    {
    private:
        uint32_t m_Id;
        std::unordered_map<std::string, int> m_UniformLocationCache;
    public:
        Shader(const std::string& vertexSource, const std::string& fragmentSource);
        ~Shader();

        void Bind() const;
        void Unbind() const;

        // Set uniforms
        void SetUniform1i(const std::string& name, int v);
        void SetUniform1f(const std::string& name, float v);
        void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    private:
        uint32_t CompileShader(uint32_t type, const std::string& source);
        uint32_t CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

        int GetUniformLocation(const std::string& name);
    };
}
