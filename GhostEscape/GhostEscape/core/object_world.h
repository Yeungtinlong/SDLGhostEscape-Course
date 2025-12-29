#pragma once

#include <GhostEscape/affiliate/collider.h>
#include <GhostEscape/core/object_screen.h>

class ObjectWorld : public ObjectScreen {
protected:
    glm::vec2 _position = glm::vec2 { .0f, .0f };
    Collider* _collider = nullptr;

public:
    virtual void init() override { _type = ObjectType::OBJECT_WORLD; }
    virtual void update(float dt) override;

    // getters
    virtual glm::vec2 getPosition() override { return _position; }
    Collider* getCollider() { return _collider; }

    // setters
    void setPosition(const glm::vec2& position);
    virtual void setRenderPosition(const glm::vec2& render_position) override;
    void setCollider(Collider* collider) { _collider = collider; }
};