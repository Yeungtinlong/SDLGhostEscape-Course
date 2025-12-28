#include <GhostEscape/affiliate/sprite_anim.h>
#include <GhostEscape/enemy.h>

void Enemy::aim_target(Player* target)
{
    if (target == nullptr) {
        _velocity = glm::vec2(0.0f);
        return;
    }
    auto direction = target->getPosition() - this->getPosition();
    direction = glm::normalize(direction);
    _velocity = direction * _max_speed;
}

void Enemy::init()
{
    Actor::init();
    _max_speed = 100.0f;
    SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-Sheet.png", glm::vec2 { 0.0f }, 2.0f);
}

void Enemy::update(float dt)
{
    Actor::update(dt);
    aim_target(_player);
    move(dt);
}