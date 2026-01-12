#include <GhostEscape/raw/stats.h>

Stats* Stats::addStatsChild(Actor* parent, float max_health, float max_mana, float damage, float mana_regen)
{
    Stats* stats = new Stats();
    stats->init();
    stats->setMaxHealth(max_health);
    stats->setMaxMana(max_mana);
    stats->setDamage(damage);
    stats->setManaRegen(mana_regen);

    parent->addChild(stats);
    stats->setParent(parent);
    return stats;
}

void Stats::update(float dt)
{
    Object::update(dt);
    regenMana(dt);
    if (_is_invincible) {
        _invincible_timer -= dt;
        if (_invincible_timer <= 0.0f) {
            _is_invincible = false;
        }
    }
}

bool Stats::canUseMana(float mana_cost)
{
    return _mana >= mana_cost;
}

void Stats::regenMana(float dt)
{
    _mana += dt * _mana_regen;
    if (_mana > _max_mana)
        _mana = _max_mana;
}

void Stats::takeDamage(float damage)
{
    if (_is_invincible || !_is_alive)
        return;
    _health -= damage;
    if (_health < 0.0f) {
        _health = 0.0f;
        _is_alive = false;
    }
    _is_invincible = true;
    _invincible_timer = _invincible_time;
    SDL_Log("Health: %f", _health);
}

void Stats::useMana(float mana_cost)
{
    _mana -= mana_cost;
    if (_mana < 0.0f)
        _mana = 0.0f;
}