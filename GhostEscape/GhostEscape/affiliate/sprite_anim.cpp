#include <GhostEscape/affiliate/sprite_anim.h>

void SpriteAnim::update(float dt)
{
    Sprite::update(dt);
    _current_frame = static_cast<int>(_frame_timer * _fps) % _total_frames;
    _frame_timer += dt;
}

void SpriteAnim::render()
{
    _texture.src_rect.x = _current_frame * _texture.src_rect.w;
    glm::vec2 render_size = _size * _scale;
    game.renderTexture(_texture, _parent->getRenderPosition() + _offset - 0.5f * render_size, render_size);
    // SDL_Log("Current Frame: %d\n", _current_frame);
}

SpriteAnim* SpriteAnim::addSpriteAnimChild(ObjectScreen* parent, const std::string& file_path, const glm::vec2& offset, float scale)
{
    auto* sprite = new SpriteAnim();
    sprite->init();
    sprite->setTexture(Texture(file_path));
    sprite->setParent(parent);
    sprite->setOffset(offset);
    sprite->setScale(scale);
    parent->addChild(sprite);
    return sprite;
}

void SpriteAnim::setTexture(Texture texture)
{
    _texture = texture;
    _total_frames = static_cast<int>(_texture.src_rect.w / _texture.src_rect.h);
    _texture.src_rect.w = _texture.src_rect.h;
    _size = glm::vec2 { _texture.src_rect.w, _texture.src_rect.h };
}