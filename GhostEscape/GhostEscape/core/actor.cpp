#include <GhostEscape/core/actor.h>
#include <GhostEscape/core/scene.h>
#include <GhostEscape/raw/stats.h>
#include <glm/glm.hpp>

void Actor::move(float dt)
{
    setPosition(_position + _velocity * dt);
    _position = glm::clamp(_position, glm::vec2(0.0f), game.getCurrentScene()->getWorldSize() - glm::vec2(20.0f));
}

void Actor::takeDamage(float damage)
{
    if (_stats != nullptr)
        _stats->takeDamage(damage);
}

bool Actor::getIsAlive()
{
    if (_stats != nullptr)
        return _stats->getIsAlive();
    return false;
}