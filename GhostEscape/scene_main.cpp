#include <GhostEscape/scene_main.h>

void SceneMain::init()
{
    _world_size = game.getScreenSize() * 3.0f;
}

void SceneMain::handleEvents(const SDL_Event& event)
{
}

void SceneMain::update(float dt)
{
}

void SceneMain::render()
{
    renderBackground();
}

void SceneMain::clean()
{
}

void SceneMain::renderBackground()
{
    glm::vec2 top_left = -_camera_position;
    glm::vec2 bottom_right = top_left + _world_size;
    game.drawGrid(top_left, bottom_right, 80, { 0.5f, 0.5f, 0.5f, 1.0f });
}
