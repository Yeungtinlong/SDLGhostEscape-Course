#include <GhostEscape/affiliate/collider.h>

bool Collider::isCollidingWith(const Collider* other)
{
    if (_type == ColliderType::COLLIDER_CIRCLE && other->_type == ColliderType::COLLIDER_CIRCLE) {
        glm::vec2 p1 = _parent->getPosition() + _offset + glm::vec2 { _size.x * 0.5f };
        glm::vec2 p2 = other->_parent->getPosition() + other->_offset + glm::vec2 { other->_size.x * 0.5f };
        return (_size.x + other->_size.x) * 0.5f > glm::distance(p1, p2);
    }
    // TODO: 实现其它碰撞类型
    return false;
}

Collider* Collider::addColliderChild(ObjectScreen* parent, const glm::vec2& size, ColliderType type)
{
    Collider* collider = new Collider();
    collider->init();
    collider->setColliderType(type);
    collider->setSize(size);
    collider->setParent(parent);
    parent->addChild(collider);

    return collider;
}

void Collider::render()
{
#ifdef DEBUG_MODE
    game.renderFillCircle(_parent->getRenderPosition() + _offset - _size * 0.5f, _size);
#endif
}