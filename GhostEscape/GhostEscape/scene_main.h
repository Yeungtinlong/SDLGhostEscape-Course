#pragma once

#include <GhostEscape/core/scene.h>

class Player;
class SceneMain : public Scene {
    Player* _player = nullptr;

private:
    void renderBackground();

public:
    SceneMain() = default;
    virtual ~SceneMain() = default; // 所有类不在构造、析构函数里做任何事

    virtual void init() override;
    virtual void handleEvents(const SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;
};