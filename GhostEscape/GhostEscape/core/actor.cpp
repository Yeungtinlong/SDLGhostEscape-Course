#include <GhostEscape/core/actor.h>
#include <GhostEscape/core/scene.h>
#include <glm/glm.hpp>

void Actor::move(float dt)
{
    setPosition(_position + _velocity * dt);
    _position = glm::clamp(_position, glm::vec2(0.0f), game.getCurrentScene()->getWorldSize() - glm::vec2(20.0f));
}