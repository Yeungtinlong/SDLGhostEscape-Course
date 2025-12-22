set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

add_executable(${TARGET})

target_sources(${TARGET}
    PRIVATE
    "GhostEscape/main.cpp"
    "GhostEscape/scene_main.cpp"
    "GhostEscape/player.cpp"

    "GhostEscape/core/game.cpp"
    "GhostEscape/core/object.cpp"
    # "GhostEscape/core/scene.cpp"
    "GhostEscape/core/object_screen.cpp"
    "GhostEscape/core/object_world.cpp"
)

# target_include_directories(${TARGET} PUBLIC 
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(${TARGET} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(${TARGET}
    PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        SDL3_mixer::SDL3_mixer
        glm::glm
)

target_compile_features(${TARGET} PRIVATE cxx_std_17)