#include <GhostEscape/core/scene.h>

void Scene::addChild(Object* child)
{
    switch (child->getType()) {
    case ObjectType::OBJECT_WORLD:
        _children_world.push_back(dynamic_cast<ObjectWorld*>(child));
        break;
    case ObjectType::OBJECT_SCREEN:
        _children_screen.push_back(dynamic_cast<ObjectScreen*>(child));
        break;
    default:
        _children.push_back(child);
        break;
    }
}

void Scene::removeChild(Object* child)
{
    switch (child->getType()) {
    case ObjectType::OBJECT_WORLD:
        _children_world.erase(std::remove(_children_world.begin(), _children_world.end(), dynamic_cast<ObjectWorld*>(child)), _children_world.end());
        break;
    case ObjectType::OBJECT_SCREEN:
        _children_screen.erase(std::remove(_children_screen.begin(), _children_screen.end(), dynamic_cast<ObjectScreen*>(child)), _children_screen.end());
        break;
    default:
        _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
        break;
    }
}

void Scene::setCameraPosition(glm::vec2 camera_position)
{
    _camera_position = glm::clamp(camera_position, glm::vec2(-40.0f), getWorldSize() - game.getScreenSize() + glm::vec2(40.0f));
}

void Scene::handleEvents(const SDL_Event& event)
{
    Object::handleEvents(event);
    for (const auto& child : _children_screen) {
        if (_is_active)
            child->handleEvents(event);
    }
    for (const auto& child : _children_world) {
        if (_is_active)
            child->handleEvents(event);
    }
}
void Scene::update(float dt)
{
    Object::update(dt);
    for (auto it = _children_world.begin(); it != _children_world.end();) {
        auto child = *it;
        if (child->getNeedRemove()) {
            it = _children_world.erase(it);
            child->clean();
            delete child;
            continue;
        }

        if (child->getActive())
            child->update(dt);
        it++;
    }
    for (auto it = _children_screen.begin(); it != _children_screen.end();) {
        auto child = *it;
        if (child->getNeedRemove()) {
            it = _children_screen.erase(it);
            child->clean();
            delete child;
            continue;
        }

        if (child->getActive())
            child->update(dt);
        it++;
    }
}

void Scene::render()
{
    Object::render();
    for (const auto& child : _children_world) {
        if (child->getActive())
            child->render();
    }
    for (const auto& child : _children_screen) {
        if (child->getActive())
            child->render();
    }
}

void Scene::clean()
{
    for (const auto& child : _children_world) {
        child->clean();
        delete child;
    }
    _children_world.clear();
    for (const auto& child : _children_screen) {
        child->clean();
        delete child;
    }
    _children_screen.clear();
    Object::clean();
}