# 全局开关，让所有库都编译为静态库
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

get_property(allTargets GLOBAL PROPERTY TARGETS)
message(STATUS "All targets: ${allTargets}")

set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3")

set(SDL3MIXER_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3_mixer")

set(SDL3IMAGES_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3_image")

set(SDL3TTF_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3_ttf")

add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/glm")

