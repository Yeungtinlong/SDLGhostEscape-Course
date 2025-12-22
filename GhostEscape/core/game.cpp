#include "game.h"
#include <GhostEscape/core/game.h>
#include <GhostEscape/scene_main.h> // TODO: 这个include肯定是有问题的core里的类不应该依赖core外的类

Game::~Game()
{
    clean();
}

void Game::init(std::string title, int width, int height)
{
    _frame_delay = 1000000000 / _fps;
    _screen_size = glm::vec2(width, height);
    // 初始化SDL3
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init Error: %s\n", SDL_GetError());
    }

    // 不需要初始化SDL_image
    // 初始化SDL3_ttf
    if (!TTF_Init()) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_Init Error: %s\n", SDL_GetError());
    }
    // 初始化SDL3_mixer
    if (!MIX_Init()) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "MIX_Init Error: %s\n", SDL_GetError());
    }
    SDL_AudioSpec spec { SDL_AUDIO_F32, 2, 48000 };
    SDL_AudioDeviceID device = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec);
    if (device == 0) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_OpenAudioDevice Error: %s\n", SDL_GetError());
    }
    _mixer = MIX_CreateMixerDevice(device, &spec);
    if (_mixer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "MIX_CreateMixerDevice Error: %s\n", SDL_GetError());
    }
    // Track代替了SDL2的Channel概念
    _music_track = MIX_CreateTrack(_mixer);
    MIX_SetTrackGain(_music_track, 0.5f);

    // 初始化窗口、渲染器
    if (!SDL_CreateWindowAndRenderer(title.c_str(), width, height, SDL_WINDOW_RESIZABLE, &_window, &_renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindowAndRenderer Error: %s\n", SDL_GetError());
    }
    if (_window == nullptr || _renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateWindowAndRenderer Error: %s\n", SDL_GetError());
    }
    // 设置逻辑分辨率
    if (!SDL_SetRenderLogicalPresentation(_renderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_SetRenderLogicalPresentation Error: %s\n", SDL_GetError());
    }

    // SDL_Log("init success.");
    _current_scene = new SceneMain();
    _current_scene->init();
}

void Game::run()
{
    while (_is_running) {
        auto start = SDL_GetTicksNS();
        handleEvents();
        update(_dt);
        render();

        auto end = SDL_GetTicksNS();
        auto elapsed = end - start;
        if (elapsed < _frame_delay) {
            SDL_DelayNS(_frame_delay - elapsed);
            _dt = _frame_delay / 1.0e9f;
        } else {
            _dt = elapsed / 1.0e9f;
        }
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT: {
            _is_running = false;
            break;
        }

        default:
            _current_scene->handleEvents(event);
        }
    }
}

void Game::update(float dt)
{
    _current_scene->update(dt);
}

void Game::render()
{
    // SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    _current_scene->render();
    SDL_RenderPresent(_renderer);
}

void Game::clean()
{
    if (_current_scene != nullptr) {
        _current_scene->clean();
        delete _current_scene;
    }

    // 清理 MIX
    if (_music_track != nullptr)
        MIX_DestroyTrack(_music_track);
    if (_mixer != nullptr)
        MIX_DestroyMixer(_mixer);
    // 清理渲染器
    if (_renderer != nullptr)
        SDL_DestroyRenderer(_renderer);
    // 清理窗口
    if (_renderer != nullptr)
        SDL_DestroyWindow(_window);

    MIX_Quit();
    // 清理TTF
    TTF_Quit();
    // 清理SDL3
    SDL_Quit();
}

void Game::drawGrid(const glm::vec2& top_left, const glm::vec2& bottom_right, float grid_size, SDL_FColor fcolor)
{
    SDL_FColor fcolor_bk;
    SDL_GetRenderDrawColorFloat(_renderer, &fcolor_bk.r, &fcolor_bk.g, &fcolor_bk.b, &fcolor_bk.a);
    SDL_SetRenderDrawColorFloat(_renderer, fcolor.r, fcolor.g, fcolor.b, fcolor.a);
    for (float x = top_left.x; x <= bottom_right.x; x += grid_size) {
        SDL_RenderLine(_renderer, x, top_left.y, x, bottom_right.y);
    }
    for (float y = top_left.y; y <= bottom_right.y; y += grid_size) {
        SDL_RenderLine(_renderer, top_left.x, y, bottom_right.x, y);
    }
    SDL_SetRenderDrawColorFloat(_renderer, fcolor_bk.r, fcolor_bk.g, fcolor_bk.b, fcolor_bk.a);
}

void Game::drawBoundary(const glm::vec2& top_left, const glm::vec2& bottom_right, float boundary_size, SDL_FColor fcolor)
{
    SDL_FColor fcolor_bk;
    SDL_GetRenderDrawColorFloat(_renderer, &fcolor_bk.r, &fcolor_bk.g, &fcolor_bk.b, &fcolor_bk.a);
    SDL_SetRenderDrawColorFloat(_renderer, fcolor.r, fcolor.g, fcolor.b, fcolor.a);

    for (float i = 0; i < boundary_size; i++) {
        SDL_FRect rect = { top_left.x - i, top_left.y - i, bottom_right.x - top_left.x + 2 * i, bottom_right.y - top_left.y + 2 * i };
        SDL_RenderRect(_renderer, &rect);
    }

    SDL_SetRenderDrawColorFloat(_renderer, fcolor_bk.r, fcolor_bk.g, fcolor_bk.b, fcolor_bk.a);
}
