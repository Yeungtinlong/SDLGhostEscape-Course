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
    _camera_position += glm::vec2(1.f, 1.f) * 320.0f * dt;
    // SDL_Log("moving cam. (%f, %f)", _camera_position.x, _camera_position.y);
    // SDL_Log("dt. %f", dt);
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
    float grid_size = 80.0f;
    float boundary_size = 3.0f;

    float start_grid_index_x = floorf32(_camera_position.x / grid_size);
    float start_grid_index_y = floorf32(_camera_position.y / grid_size);
    glm::vec2 world_grid_count = _world_size / grid_size;
    float start_grid_index_x_valid = start_grid_index_x < 0 ? 0 : start_grid_index_x > world_grid_count.x ? world_grid_count.x : start_grid_index_x;
    float start_grid_index_y_valid = start_grid_index_y < 0 ? 0 : start_grid_index_y > world_grid_count.y ? world_grid_count.y : start_grid_index_y;

    glm::vec2 screen_size = game.getScreenSize();
    float end_grid_index_x = ceilf32((_camera_position.x + screen_size.x) / grid_size);
    float end_grid_index_y = ceilf32((_camera_position.x + screen_size.y) / grid_size);

    float end_grid_index_x_valid = end_grid_index_x < 0 ? 0 : end_grid_index_x > world_grid_count.x ? world_grid_count.x : end_grid_index_x;
    float end_grid_index_y_valid = end_grid_index_y < 0 ? 0 : end_grid_index_y > world_grid_count.y ? world_grid_count.y : end_grid_index_y;

    float grid_start_x = start_grid_index_x_valid * grid_size - _camera_position.x;
    float grid_start_y = start_grid_index_y_valid * grid_size - _camera_position.y;
    float grid_end_x = end_grid_index_x_valid * grid_size - _camera_position.x;
    float grid_end_y = end_grid_index_y_valid * grid_size - _camera_position.y;

    glm::vec2 top_left = { grid_start_x, grid_start_y };
    glm::vec2 bottom_right = { grid_end_x, grid_end_y };
    game.drawGrid(top_left, bottom_right, grid_size, { 0.5f, 0.5f, 0.5f, 1.0f });
    game.drawBoundary(top_left, bottom_right, boundary_size, { 1.0f, 1.0f, 1.0f, 1.0f });
    // SDL_Log("draw grid from (%f,%f) to (%f,%f)", top_left.x, top_left.y, bottom_right.x, bottom_right.y);
}
