#include <GhostEscape/core/game.h>

int main(int, char**)
{
    Game& game = Game::GetInstance();
    game.init("Ghost Escape", 1280, 720);
    game.run();

    // if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) { }
    // if (TTF_Init() != 0) { }

    // SDL_Window* window = SDL_CreateWindow("Ghost Escape", 800, 600, 0);
    // SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    // // SDL3 新绘制文本方式
    // TTF_TextEngine* textEngine = TTF_CreateRendererTextEngine(renderer);
    // TTF_Font* font = TTF_OpenFont("assets/font/VonwaonBitmap-16px.ttf", 16);
    // if (font == nullptr) {
    //     SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_OpenFont Error: %s\n", SDL_GetError());
    // }
    // TTF_Text* text = TTF_CreateText(textEngine, font, "SDL3 新渲染方式", 0);
    // if (text == nullptr) {
    //     SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_CreateText Error: %s\n", SDL_GetError());
    // }

    // glm::vec2 mousePos { 0, 0 };
    // while (true) {
    //     SDL_Event event;
    //     if (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_EVENT_QUIT) {
    //             break;
    //         }
    //     }

    //     auto state = SDL_GetMouseState(&mousePos.x, &mousePos.y);
    //     if ((state & SDL_BUTTON_LEFT) != 0)
    //         SDL_Log("Mouse Pos: (x: %d, y:%d)\n", static_cast<int>(mousePos.x), static_cast<int>(mousePos.y));

    //     SDL_RenderClear(renderer);

    //     TTF_SetTextColor(text, 255, 255, 255, 255);
    //     TTF_DrawRendererText(text, 400, 400);

    //     SDL_RenderPresent(renderer);
    // }

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);

    // TTF_CloseFont(font);
    // TTF_Quit();

    // SDL_Quit();

    return 0;
}