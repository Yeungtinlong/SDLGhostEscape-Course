cmake_minimum_required(VERSION 3.10)

project(GhostEscape VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glm REQUIRED)

set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("3rdparty/SDL3")

set(SDL3MIXER_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("3rdparty/SDL3_mixer")

set(SDL3IMAGES_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("3rdparty/SDL3_image")

set(SDL3TTF_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("3rdparty/SDL3_ttf")

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})


add_executable(${TARGET}
    "GhostEscape/main.cpp"
    "GhostEscape/core/game.cpp"
    "GhostEscape/core/object.cpp"
    "GhostEscape/core/scene.cpp"
    "GhostEscape/scene_main.cpp"
)

target_include_directories(${TARGET} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_link_libraries(${TARGET}
    PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        SDL3_mixer::SDL3_mixer
        glm::glm
)