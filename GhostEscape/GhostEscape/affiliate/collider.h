#pragma once

#include <GhostEscape/core/object_affiliate.h>

class Collider : public ObjectAffiliate {
protected:
    enum class ColliderType {
        COLLIDER_CIRCLE, // _size.x is radius*2 for CIRCLE
        COLLIDER_RECTANGLE,
    };

    ColliderType _type = ColliderType::COLLIDER_CIRCLE;

public:
    static Collider* addColliderChild(ObjectScreen* parent, const glm::vec2& size, ColliderType type = ColliderType::COLLIDER_CIRCLE);

    virtual void render() override;

    bool isCollidingWith(const Collider* other);

    // getters and setters
    ColliderType getColliderType() { return _type; }
    void setColliderType(ColliderType type) { _type = type; }
};