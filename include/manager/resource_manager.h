#ifndef XRENDER_INCLUDE_MANGER_RESOURCE_MANAGER_H_
#define XRENDER_INCLUDE_MANGER_RESOURCE_MANAGER_H_

#include <GL/glew.h>
#include <Windows.h>
#include <stb_image.h>

#include <fstream>
#include <iostream>
#include <optional>
#include <string_view>

namespace xrn {
class ResourceManager {
 public:
  ResourceManager() = default;
  ~ResourceManager() = default;

  static auto &GetInstance() {
    static ResourceManager instance;
    return instance;
  }

  std::string LoadTextFile(std::string_view path);
  unsigned int LoadTexture(std::string_view path);
  std::string GetCurrentDirectoryOfExcecutableFile();

 private:
};

}  // namespace xrn

#endif  // XRENDER_INCLUDE_MANGER_RESOURCE_MANAGER_H_