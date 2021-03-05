#include "resource_manager.h"

namespace xrn {

std::string ResourceManager::LoadTextFile(std::string_view path) {
  auto in = std::ifstream(GetCurrentDirectoryOfExcecutableFile() + path.data(),
                          std::ios::in);
  in.exceptions(std::ifstream::badbit);

  // TODO: exception handling
  if (!in) {
    std::cerr << "ResourceManager: error load file " << path.data() << "\n";
    return "\0";
  }

  return std::string(std::istreambuf_iterator<char>(in),
                     std::istreambuf_iterator<char>());
}

unsigned int ResourceManager::LoadTexture(std::string_view path) {
  stbi_set_flip_vertically_on_load(true);
  int width, height, nr_components;
  std::string full_path = GetCurrentDirectoryOfExcecutableFile() + path.data();
  unsigned char *data =
      stbi_load(full_path.c_str(), &width, &height, &nr_components, 0);

  if (!data) {
    // TODO: exception
    std::cerr << "Failed to load texture.\n";
  }

  GLenum format = 0;
  switch (nr_components) {
    case 1:
      format = GL_RED;
      break;
    case 2:
      format = GL_RG;
      break;
    case 3:
      format = GL_RGB;
      break;
    case 4:
      format = GL_RGBA;
      break;
    default:
      break;
  }

  unsigned int texture_id;
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);

  return std::move(texture_id);
}

std::string ResourceManager::GetCurrentDirectoryOfExcecutableFile() {
  char buffer[MAX_PATH];
  GetModuleFileNameA(NULL, buffer, MAX_PATH);
  std::string::size_type pos = std::string(buffer).find_last_of("\\/");

  return std::string(buffer).substr(0, pos);
}

}  // namespace xrn