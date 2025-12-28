#pragma once

#include <GhostEscape/player.h>

class Enemy : public Actor {
    Player* _player = nullptr;

private:
    virtual void update(float dt) override;

public:
    virtual void init() override;
    void aim_target(Player* target);

    // getters and setters
    Player* getTarget() { return _player; }
    void setTarget(Player* target) { _player = target; }
};