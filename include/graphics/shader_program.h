#ifndef XRENDER_INCLUDE_GRAPHICS_SHADER_PROGRAM_H_
#define XRENDER_INCLUDE_GRAPHICS_SHADER_PROGRAM_H_

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <initializer_list>
#include <memory>

#include "shader.h"
#include "unordered_map"

namespace xrn {
class ShaderProgram {
 public:
  ShaderProgram(std::initializer_list<std::shared_ptr<Shader>> shaders);
  ~ShaderProgram();

  void AttachShader(const std::shared_ptr<Shader> shader) const;
  void DetachShader(const std::shared_ptr<Shader> shader) const;
  void LinkProgram() const;
  void Use() const;

  template <typename... Uniforms>
  void SetUniform(std::string_view name, const Uniforms&... args);

  [[nodiscard]] const GLint GetUniformLocation(std::string_view name);

 private:
  GLuint id_ = 0;

  std::unordered_map<std::string, int> uniforms_;
};

// TODO: write other special template
template <typename... Uniforms>
inline void ShaderProgram::SetUniform(std::string_view name,
                                      const Uniforms&... args) {
  std::cerr << "Invalid shader specialization\n";
}

template <>
inline void ShaderProgram::SetUniform<float>(std::string_view name,
                                             const float& v0) {
  glUniform1f(GetUniformLocation(name), v0);
}

template <>
inline void ShaderProgram::SetUniform<float, float>(std::string_view name,
                                                    const float& v0,
                                                    const float& v1) {
  glUniform2f(GetUniformLocation(name), v0, v1);
}

template <>
inline void ShaderProgram::SetUniform<float, float, float>(
    std::string_view name, const float& v0, const float& v1, const float& v2) {
  glUniform3f(GetUniformLocation(name), v0, v1, v2);
}

template <>
inline void ShaderProgram::SetUniform<float, float, float, float>(
    std::string_view name, const float& v0, const float& v1, const float& v2,
    const float& v3) {
  glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

template <>
inline void ShaderProgram::SetUniform<int>(std::string_view name,
                                           const int& v0) {
  glUniform1i(GetUniformLocation(name), v0);
}

template <>
inline void ShaderProgram::SetUniform<int, int>(std::string_view name,
                                                const int& v0, const int& v1) {
  glUniform2i(GetUniformLocation(name), v0, v1);
}

template <>
inline void ShaderProgram::SetUniform<int, int, int>(std::string_view name,
                                                     const int& v0,
                                                     const int& v1,
                                                     const int& v2) {
  glUniform3i(GetUniformLocation(name), v0, v1, v2);
}

template <>
inline void ShaderProgram::SetUniform<int, int, int, int>(std::string_view name,
                                                          const int& v0,
                                                          const int& v1,
                                                          const int& v2,
                                                          const int& v3) {
  glUniform4i(GetUniformLocation(name), v0, v1, v2, v3);
}

template <>
inline void ShaderProgram::SetUniform<glm::mat4>(std::string_view name,
                                                 const glm::mat4& value) {
  glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE,
                     glm::value_ptr(value));
}
}  // namespace xrn

#endif  // XRENDER_INCLUDE_GRAPHICS_SHADER_PROGRAM_H_