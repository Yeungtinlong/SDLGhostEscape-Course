#pragma once

#include <GhostEscape/core/actor.h>

class Stats : public Object {
protected:
    Actor* _parent = nullptr;
    float _health = 100.0f;
    float _max_health = 100.0f;
    float _mana = 100.0f;
    float _max_mana = 100.0f;
    float _damage = 40.0f;
    float _mana_regen = 10.0f;

    bool _is_alive = true;
    bool _is_invincible = true;
    float _invincible_timer = 0.0f;
    float _invincible_time = 1.5f;

public:
    static Stats* addStatsChild(Actor* parent, float max_health = 100.0f, float max_mana = 100.0f, float damage = 40.0f, float mana_regen = 10.0f);

    virtual void update(float dt) override;
    bool canUseMana(float mana_cost);
    void useMana(float mana_cost);
    void regenMana(float dt);
    void takeDamage(float damage);

    // getters and setters
    float getHealth() { return _health; }
    float getMaxHealth() { return _max_health; }
    float getMana() { return _mana; }
    float getMaxMana() { return _max_mana; }
    float getDamage() { return _damage; }
    float getManaRegen() { return _mana_regen; }
    bool getIsAlive() { return _is_alive; }
    bool getIsInvincible() { return _is_invincible; }
    float getInvincibleTimer() { return _invincible_timer; }
    float getInvincibleTime() { return _invincible_time; }
    Actor* getParent() { return _parent; }

    void setHealth(float health) { _health = health; }
    void setMaxHealth(float max_health) { _max_health = max_health; }
    void setMana(float mana) { _mana = mana; }
    void setMaxMana(float max_mana) { _max_mana = max_mana; }
    void setDamage(float damage) { _damage = damage; }
    void setManaRegen(float mana_regen) { _mana_regen = mana_regen; }
    void setIsAlive(bool is_alive) { _is_alive = is_alive; }
    void setIsInvincible(bool is_invincible) { _is_invincible = is_invincible; }
    void setInvincibleTimer(float invincible_timer) { _invincible_timer = invincible_timer; }
    void setInvincibleTime(float invincible_time) { _invincible_time = invincible_time; }
    void setParent(Actor* parent) { _parent = parent; }
};