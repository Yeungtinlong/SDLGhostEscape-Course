#pragma once

#include <GhostEscape/core/object_screen.h>
// #include <GhostEscape/core/object_screen.h>

class ObjectAffiliate : public ObjectScreen {
protected:
    ObjectScreen* _parent = nullptr;
    glm::vec2 _offset { 0.0f, 0.0f };
    glm::vec2 _size { 0.0f, 0.0f };
    Anchor _anchor = Anchor::CENTER;

public:
    void setOffsetByAnchor(Anchor anchor);

    // getter and setters
    ObjectScreen* getParent() { return _parent; }
    void setParent(ObjectScreen* parent) { _parent = parent; }
    glm::vec2 getOffset() { return _offset; }
    void setOffset(glm::vec2 offset) { _offset = offset; }
    virtual glm::vec2 getSize() { return _size; }
    virtual void setSize(glm::vec2 size) { _size = size; }
    Anchor getAnchor() { return _anchor; }
    void setAnchor(Anchor anchor) { _anchor = anchor; }
};