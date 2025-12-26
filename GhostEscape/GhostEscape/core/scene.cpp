#include <GhostEscape/core/scene.h>

void Scene::setCameraPosition(glm::vec2 camera_position)
{
    _camera_position = glm::clamp(camera_position, glm::vec2(-40.0f), getWorldSize() - game.getScreenSize() + glm::vec2(40.0f));
}