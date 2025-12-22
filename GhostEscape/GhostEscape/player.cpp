#include <GhostEscape/player.h>
#include <GhostEscape/core/scene.h>

void Player::init()
{
    _max_speed = 200.0f;
}

void Player::handleEvents(const SDL_Event& event)
{
}

void Player::update(float dt)
{
    keyboardControl();
    move(dt);
    syncCamera();
}

void Player::render()
{
    game.drawBoundary(_render_position, _render_position + glm::vec2(20.0f), 5.0f, { 1.0f, 0.0f, 0.0f, 1.0f });
}

void Player::clean()
{
}

void Player::keyboardControl()
{
    auto currentKeyState = SDL_GetKeyboardState(nullptr);
    _velocity *= 0.9f;
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

void Player::move(float dt)
{
    setPosition(_position + _velocity * dt);
    _position = glm::clamp(_position, glm::vec2(0.0f), game.getCurrentScene()->getWorldSize() - glm::vec2(20.0f));
}

void Player::syncCamera()
{
    game.getCurrentScene()->setCameraPosition(_position - game.getScreenSize() * 0.5f);
}
