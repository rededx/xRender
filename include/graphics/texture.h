#ifndef XRENDER_INCLUDE_GRAPHICS_TEXTURE_H_
#define XRENDER_INCLUDE_GRAPHICS_TEXTURE_H_

#include <string_view>

#include "resource_manager.h"

namespace xrn {
class Texture {
 public:
  Texture(std::string_view path);
  ~Texture() = default;

  unsigned int get_id();

 private:
  unsigned int id_;
};

}  // namespace xrn

#endif  // XRENDER_INCLUDE_GRAPHICS_TEXTURE_H_