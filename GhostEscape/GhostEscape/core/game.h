#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <glm/glm.hpp>
#include <string>

class Scene;
class Game {
public:
    Game() { }
    ~Game();
    static Game& GetInstance()
    {
        static Game game {};
        return game;
    }

    void init(std::string title, int width, int height);
    void run();
    void handleEvents();
    void update(float dt);
    void render();
    void clean();

    // 工具函数
    void drawGrid(const glm::vec2& top_left, const glm::vec2& bottom_right, float grid_size, SDL_FColor fcolor);
    void drawBoundary(const glm::vec2& top_left, const glm::vec2& bottom_right, float boundary_size, SDL_FColor fcolor);

    // getters
    glm::vec2 getScreenSize() { return _screen_size; }
    SDL_Renderer* getRenderer() { return _renderer; }
    Scene* getCurrentScene() { return _current_scene; }

private:
    Game(Game& game) = delete;
    Game& operator=(const Game& game) = delete;

private:
    glm::vec2 _screen_size { 0.0f, 0.0f };
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;
    MIX_Mixer* _mixer = nullptr;
    MIX_Track* _music_track = nullptr;
    bool _is_running = true;
    Uint64 _fps = 60;
    Uint64 _frame_delay = 0;
    float _dt = 0.0f;
    Scene* _current_scene = nullptr;
};