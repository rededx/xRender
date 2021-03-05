#ifndef XRENDER_INCLUDE_GRAPHICS_SHADER_H_
#define XRENDER_INCLUDE_GRAPHICS_SHADER_H_

#include <GL/glew.h>
#include <resource_manager.h>

#include <array>
#include <string_view>

#include "debug.h"

namespace xrn {

enum Type : decltype(GL_VERTEX_SHADER) {
  kVertex = GL_VERTEX_SHADER,
  kGeometry = GL_GEOMETRY_SHADER,
  kFragment = GL_FRAGMENT_SHADER
};

class ShaderProgram;

class Shader {
 public:
  friend ShaderProgram;

  Shader(std::string_view path, const Type type);
  ~Shader();

  Shader(Shader&) = delete;
  Shader& operator=(Shader&) = delete;

  void Delete();

 private:
  void Compile(const GLchar* shaderCode);

 private:
  GLuint id_ = 0;
};

}  // namespace xrn
#endif  // XRENDER_INCLUDE_GRAPHICS_SHADER_H_