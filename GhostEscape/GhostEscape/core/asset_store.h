#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <string>
#include <unordered_map> // 无序列表

class AssetStore {
private:
    SDL_Renderer* _renderer = nullptr;
    MIX_Mixer* _mixer = nullptr;
    std::unordered_map<std::string, SDL_Texture*> _textures;
    std::unordered_map<std::string, TTF_Font*> _fonts;
    std::unordered_map<std::string, MIX_Audio*> _audios;

public:
    AssetStore(SDL_Renderer* renderer, MIX_Mixer* mixer)
    {
        _renderer = renderer;
        _mixer = mixer;
    }
    ~AssetStore() = default;
    void loadImage(const std::string& file_path);
    void loadFont(const std::string& file_path, int font_size);
    void loadAudio(const std::string& file_path);

    SDL_Texture* getImage(const std::string& file_path);
    TTF_Font* getFont(const std::string& file_path);
    MIX_Audio* getAudio(const std::string& file_path);

    void clean();
};