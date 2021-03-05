#ifndef XRENDER_INCLUDE_CORE_WINDOW_H_
#define XRENDER_INCLUDE_CORE_WINDOW_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <functional>
#include <memory>

#include "debug.h"
#include "window_settings.h"

namespace xrn {
class Window {
 public:
  Window() noexcept;

  Window(const WindowSettings& settings);

  Window(const Window&) = delete;
  Window(Window&&) = default;
  Window& operator=(const Window&) = delete;
  Window& operator=(Window&&) = default;

  ~Window();

  [[nodiscard]] const bool Create();
  void Destroy();

  std::pair<int, int> GetFramebufferSize() const;
  bool ShouldClose();
  void SwapBuffers() const;
  float GetAspect();
  GLFWwindow* get_window();

 private:
  GLFWwindow* window_;
  std::shared_ptr<WindowSettings> settings;
};
}  // namespace xrn

#endif  // XRENDER_INCLUDE_CORE_WINDOW_H_