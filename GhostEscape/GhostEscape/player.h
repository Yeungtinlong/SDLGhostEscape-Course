#pragma once

#include <GhostEscape/core/actor.h>
#include <GhostEscape/world/effect.h>

class SpriteAnim;

class Player : public Actor {
    SpriteAnim* _sprite_idle = nullptr;
    SpriteAnim* _sprite_move = nullptr;
    Effect* _die_effect = nullptr;
    bool _is_moving = false;

public:
    virtual void init() override;
    virtual void handleEvents(const SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

private:
    void keyboardControl();
    void syncCamera();
    void checkState();
    void changeState(bool is_moving);
    void checkIsDead();
};