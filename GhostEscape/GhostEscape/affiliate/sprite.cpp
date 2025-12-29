#include <GhostEscape/affiliate/sprite.h>
#include <GhostEscape/core/asset_store.h>

Texture::Texture(const std::string& file_path)
{
    texture = Game::GetInstance().getAssetStore()->getImage(file_path);
    if (!SDL_GetTextureSize(texture, &src_rect.w, &src_rect.h)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_GetTextureSize Error: %s\n", SDL_GetError());
    }
}

void Sprite::render()
{
    if (_texture.texture == nullptr || _parent == nullptr)
        return;

    glm::vec2 position = _parent->getRenderPosition() + _offset;
    game.renderTexture(_texture, position, _size);
}

Sprite* Sprite::addSpriteChild(ObjectScreen* parent, const std::string& file_path, const glm::vec2& offset, float scale)
{
    auto* sprite = new Sprite();
    sprite->init();
    sprite->setTexture(Texture(file_path));
    sprite->setParent(parent);
    sprite->setOffset(offset);
    sprite->setScale(scale);
    parent->addChild(sprite);
    return sprite;
}

void Sprite::setTexture(Texture texture)
{
    _texture = texture;
    _size = glm::vec2 { texture.src_rect.w, texture.src_rect.h };
}