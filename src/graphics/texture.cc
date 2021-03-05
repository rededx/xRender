#include "texture.h"

namespace xrn {

Texture::Texture(std::string_view path) {
  id_ = ResourceManager::GetInstance().LoadTexture(path);
}

unsigned int Texture::get_id() { return id_; }

}  // namespace xrn
