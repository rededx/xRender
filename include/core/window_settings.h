#ifndef XRENDER_INCLUDE_CORE_WINDOW_SETTINGS_
#define XRENDER_INCLUDE_CORE_WINDOW_SETTINGS_

#include <iostream>

namespace xrn {
// TODO: read in file of settings
struct WindowSettings {
  std::string title = "xRender";

  float line_thickness;

  // MSAA level. I.e. 2, 4, 8, etc.
  int anti_aliasing;
  int anisotropic_filtering;
  // -1 ignore
  int aspect_ratio_x;
  // -1 ignore
  int aspect_ratio_y;
  int width = 900;
  int height = 600;

  bool raw_mouse_input;
  bool vsync;
  bool gl_debug;
};
}  // namespace xrender

#endif  // XRENDER_INCLUDE_CORE_WINDOW_SETTINGS_