#include <GhostEscape/core/asset_store.h>

void AssetStore::loadImage(const std::string& file_path)
{
    SDL_Texture* texture = IMG_LoadTexture(_renderer, file_path.c_str());
    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "IMG_LoadTexture Error: %s\n", SDL_GetError());
        return;
    }
    _textures.emplace(file_path, texture);
}

void AssetStore::loadFont(const std::string& file_path, int font_size)
{
    TTF_Font* font = TTF_OpenFont(file_path.c_str(), font_size);
    if (font == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "TTF_OpenFont Error: %s\n", SDL_GetError());
        return;
    }
    _fonts.emplace(file_path + std::to_string(font_size), font);
}

void AssetStore::loadAudio(const std::string& file_path)
{
    MIX_Audio* audio = MIX_LoadAudio(_mixer, file_path.c_str(), true);
    if (audio == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "MIX_LoadAudio Error: %s\n", SDL_GetError());
        return;
    }
    _audios.emplace(file_path, audio);
}

SDL_Texture* AssetStore::getImage(const std::string& file_path)
{
    auto iter = _textures.find(file_path);
    if (iter == _textures.end()) {
        loadImage(file_path);
        iter = _textures.find(file_path);
        if (iter == _textures.end()) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Fail to get image: %s\n", file_path.c_str());
            return nullptr;
        }
    }

    return iter->second;
}

TTF_Font* AssetStore::getFont(const std::string& file_path)
{
    auto iter = _fonts.find(file_path);
    if (iter == _fonts.end()) {
        loadImage(file_path);
        iter = _fonts.find(file_path);
        if (iter == _fonts.end()) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Fail to get font: %s\n", file_path.c_str());
            return nullptr;
        }
    }

    return iter->second;
}

MIX_Audio* AssetStore::getAudio(const std::string& file_path)
{
    auto iter = _audios.find(file_path);
    if (iter == _audios.end()) {
        loadImage(file_path);
        iter = _audios.find(file_path);
        if (iter == _audios.end()) {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Fail to get audio: %s\n", file_path.c_str());
            return nullptr;
        }
    }

    return iter->second;
}

void AssetStore::clean()
{
    for (const auto& texture : _textures) {
        SDL_DestroyTexture(texture.second);
    }
    _textures.clear();
    for (const auto& audio : _audios) {
        MIX_DestroyAudio(audio.second);
    }
    _audios.clear();
    for (const auto& font : _fonts) {
        TTF_CloseFont(font.second);
    }
    _fonts.clear();
}
