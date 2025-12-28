# 全局开关，让所有库都编译为静态库
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

add_subdirectory(3rdparty/freetype)

# 告诉 SDL_ttf 用这个
set(FREETYPE_INCLUDE_DIRS
    $<TARGET_PROPERTY:freetype,INTERFACE_INCLUDE_DIRECTORIES>)

set(FREETYPE_LIBRARY freetype)


set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3")

set(SDL3MIXER_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3_mixer")

set(SDL3IMAGES_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3_image")

set(SDL3TTF_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/SDL3_ttf")

# glm header-only library, change to add git submodule
# find_package(glm REQUIRED)
add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/glm")

