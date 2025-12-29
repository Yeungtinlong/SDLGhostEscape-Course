#pragma once

#include <GhostEscape/player.h>

class Enemy : public Actor {

    enum class State {
        NORMAL,
        HURT,
        DIE
    };

    Player* _player = nullptr;
    SpriteAnim* _anim_normal = nullptr;
    SpriteAnim* _anim_hurt = nullptr;
    SpriteAnim* _anim_die = nullptr;
    SpriteAnim* _current_anim = nullptr;
    State _current_state = State::NORMAL;

    float _temp_timer = 0.0f;

private:
    virtual void update(float dt) override;
    void checkState();
    void changeState(State state);

public:
    virtual void init() override;
    void remove();
    void aim_target(Player* target);
    void attack();

    // getters and setters
    Player* getTarget() { return _player; }
    void setTarget(Player* target) { _player = target; }
};