#include "shader_program.h"

namespace xrn {
ShaderProgram::ShaderProgram(
    std::initializer_list<std::shared_ptr<Shader>> shaders) {
  id_ = glCreateProgram();

  for (auto& shader : shaders) {
    glAttachShader(id_, shader->id_);
  }
}

ShaderProgram::~ShaderProgram() {}

void ShaderProgram::AttachShader(const std::shared_ptr<Shader> shader) const {
  glAttachShader(id_, shader->id_);
}

void ShaderProgram::DetachShader(const std::shared_ptr<Shader> shader) const {
  glDetachShader(id_, shader->id_);
}

void ShaderProgram::LinkProgram() const {
  GLint success;
  std::array<GLchar, 1024> info_log;

  glLinkProgram(id_);

  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(id_, info_log.size(), nullptr, info_log.data());
    std::cerr << "Link error: " << info_log.data() << "\n";
  }
}

void ShaderProgram::Use() const { glUseProgram(id_); }

[[nodiscard]] const GLint ShaderProgram::GetUniformLocation(
    std::string_view name) {
  if (uniforms_.count(name.data())) return uniforms_.at(name.data());

  const auto location = glGetUniformLocation(id_, name.data());
  if (location != -1)
    uniforms_.emplace(name, location);
  else
    std::cerr << "Failed to find uniform: " << name.data() << "\n";

  return location;
}
}  // namespace xrn
