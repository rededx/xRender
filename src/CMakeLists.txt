add_compile_definitions(GLEW_STATIC _DEBUG)

find_package(OpenGL REQUIRED)

set(XRENDER_SRC_DIR
"${CMAKE_SOURCE_DIR}/src/core/window.cc"
"${CMAKE_SOURCE_DIR}/src/core/window_settings.cc"
"${CMAKE_SOURCE_DIR}/src/graphics/shader.cc"
"${CMAKE_SOURCE_DIR}/src/graphics/shader_program.cc"
"${CMAKE_SOURCE_DIR}/src/graphics/texture.cc"
"${CMAKE_SOURCE_DIR}/src/manager/resource_manager.cc"
"${CMAKE_SOURCE_DIR}/src/core/engine.cc"
"${CMAKE_SOURCE_DIR}/external/stb/include/stb_image.cpp"
)
set(XRENDER_INCLUDE_DIR
"${CMAKE_SOURCE_DIR}/include/core/window.h"
"${CMAKE_SOURCE_DIR}/include/core/window_settings.h"
    "${CMAKE_SOURCE_DIR}/include/graphics/shader.h")

add_library(xRender STATIC ${XRENDER_SRC_DIR})

set_target_properties(
  xRender
  PROPERTIES
    VERSION ${PROJECT_VERSION} # SOVERSION 1
    PUBLIC_HEADER
    "${CMAKE_SOURCE_DIR}/include/window.h;${CMAKE_SOURCE_DIR}/include/window_settings.h"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)
target_include_directories(xRender PRIVATE "${CMAKE_SOURCE_DIR}/include"
                                           "${CMAKE_SOURCE_DIR}/include/core"
                                           "${CMAKE_SOURCE_DIR}/include/graphics"
                                           "${CMAKE_SOURCE_DIR}/include/manager"
                                           "${CMAKE_SOURCE_DIR}/external/stb/include"
                                           "${CMAKE_SOURCE_DIR}/external/stb"
                                           )

add_library(glew32s STATIC IMPORTED)
set_target_properties(
  glew32s
  PROPERTIES IMPORTED_LOCATION
             "${CMAKE_SOURCE_DIR}/external/glew/lib/glew32sd.lib"
             INTERFACE_INCLUDE_DIRECTORIES
             "${CMAKE_SOURCE_DIR}/external/glew/include")

target_link_libraries(xRender OpenGL::GL glfw glm glew32s)


# TODO: implement later install( TARGETS xRender LIBRARY DESTINATION
# "${CMAKE_SOURCE_DIR}/out/bin" PUBLIC_HEADER DESTINATION
# "${CMAKE_SOURCE_DIR}/out/include")
