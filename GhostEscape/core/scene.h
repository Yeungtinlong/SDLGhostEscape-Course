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

protected:
    glm::vec2 _camera_position { .0f, .0f };
    std::vector<Object*> _objects {};
};