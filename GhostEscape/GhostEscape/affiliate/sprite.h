#pragma once

#include <GhostEscape/core/object_affiliate.h>

struct Texture {
    SDL_Texture* texture = nullptr;
    SDL_FRect src_rect { .0f, .0f, .0f, .0f };
    float angle = 0;
    bool is_flip = false;
    Texture() = default;
    Texture(const std::string& file_path);
};

class Sprite : public ObjectAffiliate {
protected:
    Texture _texture;
    float _scale = 1.0f;
    virtual void render() override;

public:
    static Sprite* addSpriteChild(ObjectScreen* parent, const std::string& file_path, const glm::vec2& offset, float scale = 1.0f);

    // getters
    Texture getTexture() { return _texture; }
    float getAngle() { return _texture.angle; }
    bool getFlip() { return _texture.is_flip; }
    float getScale() { return _scale; }

    // setters
    virtual void setTexture(Texture texture);
    void setAngle(float angle) { _texture.angle = angle; }
    void setFlip(bool is_flip) { _texture.is_flip = is_flip; }
    void setScale(float scale) { _scale = scale; }
};