#include <GhostEscape/core/object.h>

void Object::handleEvents(const SDL_Event& event)
{
    for (const auto& child : _children) {
        if (child->getActive())
            child->handleEvents(event);
    }
}
void Object::update(float dt)
{
    for (const auto& child : _children) {
        if (child->getActive())
            child->update(dt);
    }
}
void Object::render()
{
    for (const auto& child : _children) {
        if (child->getActive())
            child->render();
    }
}
void Object::clean()
{
    for (const auto& child : _children) {
        child->clean();
        delete child;
    }
    _children.clear();
}
