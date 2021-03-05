#include "window.h"

namespace xrn {

Window::Window() noexcept : window_(nullptr) {
  settings = std::make_shared<WindowSettings>();
}

Window::~Window() { Destroy(); }

[[nodiscard]] const bool Window::Create() {
  if (!glfwInit()) {
    std::cerr << "Failed to initalise glfw!";
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// TODO: test later
#ifndef _APPLE_
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif  // _APPLE_

  // TODO: think it, maybe activate later
  // glfwWindowHint(GLFW_SAMPLES, 5);

#ifndef _DEBUG
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif _DEBUG

  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
  glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
  glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
  glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
  glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

  // TODO: MSAA

  window_ = glfwCreateWindow(settings->width, settings->height,
                             settings->title.c_str(), nullptr, nullptr);
  if (window_ == nullptr) {
    std::cerr << "Failed to create GLFW window.\n";
    glfwDestroyWindow(window_);
    return false;
  }

  glfwMakeContextCurrent(window_);
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialise GLEW.\n";
    glfwDestroyWindow(window_);
    return false;
  }

  const auto& sizeFramebuffer{this->GetFramebufferSize()};
  glViewport(0, 0, sizeFramebuffer.first, sizeFramebuffer.second);

  return true;
}

void Window::Destroy() {
  if (window_ != nullptr) {
    DEBUG("Destroy window.");

    glfwDestroyWindow(window_);
    window_ = nullptr;
  }

  glfwTerminate();

  DEBUG("glfw terminated.");
}

std::pair<int, int> Window::GetFramebufferSize() const {
  int width, height;
  glfwGetFramebufferSize(window_, &width, &height);
  return {width, height};
}

bool Window::ShouldClose() { return glfwWindowShouldClose(window_); }

void Window::SwapBuffers() const { glfwSwapBuffers(window_); }

float Window::GetAspect() {
  return (float)settings->width / (float)settings->height;
}

GLFWwindow* Window::get_window() { return window_; }

}  // namespace xrn
