#include <GhostEscape/core/object_affiliate.h>

void ObjectAffiliate::setOffsetByAnchor(Anchor anchor)
{
    switch (anchor) {
    case Anchor::TOP_LEFT:
        _offset = glm::vec2(0.0f, 0.0f);
        break;
    case Anchor::TOP_CENTER:
        _offset = glm::vec2(-getSize().x / 2.0f, 0.0f);
        break;
    case Anchor::TOP_RIGHT:
        _offset = glm::vec2(-getSize().x, 0.0f);
        break;
    case Anchor::CENTER_LEFT:
        _offset = glm::vec2(0.0f, -getSize().y / 2.0f);
        break;
    case Anchor::CENTER:
        _offset = glm::vec2(-getSize().x / 2.0f, -getSize().y / 2.0f);
        break;
    case Anchor::CENTER_RIGHT:
        _offset = glm::vec2(-getSize().x, -getSize().y / 2.0f);
        break;
    case Anchor::BOTTOM_LEFT:
        _offset = glm::vec2(0.0f, -getSize().y);
        break;
    case Anchor::BOTTOM_CENTER:
        _offset = glm::vec2(-getSize().x / 2.0f, -getSize().y);
        break;
    case Anchor::BOTTOM_RIGHT:
        _offset = glm::vec2(-getSize().x, -getSize().y);
        break;
    default:
        _offset = glm::vec2(0.0f, 0.0f);
        break;
    }
}