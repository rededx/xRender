#include "shader.h"
namespace xrn {
Shader::Shader(std::string_view path, const Type type) {
  id_ = glCreateShader(type);

  auto shaderCode = ResourceManager::GetInstance().LoadTextFile(path);

  Compile(shaderCode.c_str());
}

Shader::~Shader() { Delete(); }

void Shader::Compile(const GLchar* shaderCode) {
  DEBUG("Compiling shader...");

  GLint success;
  std::array<GLchar, 1024> info_log;

  glShaderSource(id_, 1, &shaderCode, nullptr);
  glCompileShader(id_);

  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(id_, info_log.size(), nullptr, info_log.data());
    std::cerr << "Shader error: " << info_log.data() << "\n";
  }

  DEBUG("Compilation successful.");
}

void Shader::Delete() {
  if (id_ != 0) {
    glDeleteShader(id_);
    id_ = 0;
  }
}

}  // namespace xrn