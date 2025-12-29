#include <GhostEscape/affiliate/collider.h>
#include <GhostEscape/affiliate/sprite_anim.h>
#include <GhostEscape/core/scene.h>
#include <GhostEscape/player.h>

void Player::init()
{
    Actor::init();
    _max_speed = 500.0f;
    _sprite_idle = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-idle.png", glm::vec2 { 0.0f }, 2.0f);
    _sprite_move = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-move.png", glm::vec2 { 0.0f }, 2.0f);
    _sprite_move->setActive(false);

    _collider = Collider::addColliderChild(this, _sprite_idle->getSize());
}

void Player::handleEvents(const SDL_Event& event)
{
    Actor::handleEvents(event);
}

void Player::update(float dt)
{
    Actor::update(dt);
    _velocity *= 0.9f;
    keyboardControl();
    move(dt);
    syncCamera();
    checkState();
}

void Player::render()
{
    Actor::render();
    // game.drawBoundary(_render_position, _render_position + glm::vec2(20.0f), 5.0f, { 1.0f, 0.0f, 0.0f, 1.0f });
}

void Player::clean()
{
    Actor::clean();
}

void Player::keyboardControl()
{
    auto currentKeyState = SDL_GetKeyboardState(nullptr);
    if (currentKeyState[SDL_SCANCODE_W]) {
        _velocity.y = -_max_speed;
    }
    if (currentKeyState[SDL_SCANCODE_S]) {
        _velocity.y = _max_speed;
    }
    if (currentKeyState[SDL_SCANCODE_A]) {
        _velocity.x = -_max_speed;
    }
    if (currentKeyState[SDL_SCANCODE_D]) {
        _velocity.x = _max_speed;
    }
}

void Player::syncCamera()
{
    game.getCurrentScene()->setCameraPosition(_position - game.getScreenSize() * 0.5f);
}

void Player::checkState()
{
    _sprite_move->setFlip(_velocity.x < 0);
    _sprite_idle->setFlip(_velocity.x < 0);

    bool new_is_moving = glm::length(_velocity) > 0.1f;

    if (new_is_moving != _is_moving) {
        _is_moving = new_is_moving;
        changeState(_is_moving);
    }
}

void Player::changeState(bool is_moving)
{
    _sprite_move->setActive(is_moving);
    _sprite_idle->setActive(!is_moving);
    if (is_moving) {
        _sprite_move->setCurrentFrame(_sprite_idle->getCurrentFrame());
        _sprite_move->setFrameTimer(_sprite_idle->getFrameTimer());
    } else {
        _sprite_idle->setCurrentFrame(_sprite_move->getCurrentFrame());
        _sprite_idle->setFrameTimer(_sprite_move->getFrameTimer());
    }
}