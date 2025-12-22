#pragma once

#include <GhostEscape/core/actor.h>

class Player : public Actor {
public:
    virtual void init() override;
    virtual void handleEvents(const SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

private:
    void keyboardControl();
    void move(float dt);
    void syncCamera();
};