#pragma once

#include <GhostEscape/core/defs.h>
#include <GhostEscape/core/game.h>
#include <SDL3/SDL.h>

class Object {
protected:
    ObjectType _type = ObjectType::NONE;
    Game& game = Game::GetInstance();
    std::vector<Object*> _children;
    bool _is_active = true;
    bool _need_remove = false;

public:
    Object() = default;
    virtual ~Object() = default; // 所有类不在构造、析构函数里做任何事

    virtual void init() { }
    virtual void handleEvents(const SDL_Event& event);
    virtual void update(float dt);
    virtual void render();
    virtual void clean();

    virtual void addChild(Object* child) { _children.push_back(child); }
    virtual void removeChild(Object* child)
    {
        _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
    }
    // getters
    ObjectType getType() const { return _type; }
    bool getActive() const { return _is_active; }
    bool getNeedRemove() { return _need_remove; }
    // setters
    void setType(ObjectType type) { _type = type; }
    void setActive(bool is_active) { _is_active = is_active; }
};
