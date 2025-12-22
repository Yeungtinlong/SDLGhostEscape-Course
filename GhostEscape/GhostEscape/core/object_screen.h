#pragma once

#include <GhostEscape/core/object.h>

class ObjectScreen : public Object {
protected:
    glm::vec2 _render_position = glm::vec2 { 0.f, 0.f };

public:
    glm::vec2 getRenderPosition() const { return _render_position; }
    virtual void setRenderPosition(const glm::vec2& render_position) { _render_position = render_position; }
};