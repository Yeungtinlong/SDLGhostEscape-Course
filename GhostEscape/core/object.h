#pragma once

#include <GhostEscape/core/game.h>
#include <SDL3/SDL.h>

class Object {
public:
    Object() = default;
    virtual ~Object() = default; // 所有类不在构造、析构函数里做任何事

    virtual void init() { }
    virtual void handleEvents(const SDL_Event& event) { }
    virtual void update(float dt) { }
    virtual void render() { }
    virtual void clean() { }

protected:
    Game& game = Game::GetInstance();
};
