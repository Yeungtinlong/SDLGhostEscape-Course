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
    for (auto it = _children.begin(); it != _children.end();) {
        auto child = *it;
        if (child->_need_remove) {
            it = _children.erase(it);
            child->clean();
            delete child;
            continue;
        }

        if (child->getActive())
            child->update(dt);
        it++;
    }

    for (const auto& child : _children) {
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
