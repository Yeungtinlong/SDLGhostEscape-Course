#include <GhostEscape/core/object_world.h>
#include <GhostEscape/core/scene.h>

void ObjectWorld::setPosition(const glm::vec2& position)
{
    _position = position;
    _render_position = game.getCurrentScene()->worldToScreen(_position);
}

void ObjectWorld::setRenderPosition(const glm::vec2& render_position)
{
    _render_position = render_position;
    _position = game.getCurrentScene()->screenToWorld(_render_position);
}

void ObjectWorld::update(float dt)
{
    ObjectScreen::update(dt);
    _render_position = game.getCurrentScene()->worldToScreen(_position);
}