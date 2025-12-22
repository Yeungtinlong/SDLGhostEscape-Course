#pragma once

#include <GhostEscape/core/object.h>
#include <SDL3/SDL.h>
#include <glm/glm.hpp>
#include <vector>

class Scene : public Object {
public:
    Scene() = default;
    virtual ~Scene() = default; // 所有类不在构造、析构函数里做任何事

    virtual void init() override { }
    virtual void handleEvents(const SDL_Event& event) override { }
    virtual void update(float dt) override { }
    virtual void render() override { }
    virtual void clean() override { }

    glm::vec2 worldToScreen(glm::vec2 world_position) const { return world_position - _camera_position; }
    glm::vec2 screenToWorld(glm::vec2 screen_position) const { return _camera_position + screen_position; }

    // getters
    glm::vec2 getCameraPosition() { return _camera_position; }
    glm::vec2 getWorldSize() { return _world_size; }
    // setters
    void setCameraPosition(glm::vec2 camera_position) { _camera_position = camera_position; }

protected:
    glm::vec2 _camera_position { .0f, .0f };
    glm::vec2 _world_size = { .0f, .0f };
    std::vector<Object*> _objects {};
};