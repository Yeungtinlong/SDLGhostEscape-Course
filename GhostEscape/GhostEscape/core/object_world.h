#pragma once

#include <GhostEscape/core/object_screen.h>

class ObjectWorld : public ObjectScreen {
protected:
    glm::vec2 _position = glm::vec2 { .0f, .0f };

public:
    virtual void update(float dt) override;

    // getters
    glm::vec2 getPosition() const { return _position; }

    // setters
    void setPosition(const glm::vec2& position);
    virtual void setRenderPosition(const glm::vec2& render_position) override;
};