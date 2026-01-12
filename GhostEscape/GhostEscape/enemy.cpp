#include <GhostEscape/affiliate/sprite_anim.h>
#include <GhostEscape/core/scene.h>
#include <GhostEscape/enemy.h>
#include <GhostEscape/raw/stats.h>

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
    _anim_normal = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghost-Sheet.png", 1.5f);
    _anim_hurt = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghostHurt-Sheet.png", 1.5f);
    _anim_die = SpriteAnim::addSpriteAnimChild(this, "assets/sprite/ghostDead-Sheet.png", 1.5f);
    _current_anim = _anim_normal;
    _anim_hurt->setActive(false);
    _anim_die->setActive(false);
    _anim_die->setIsLoop(false);

    _collider = Collider::addColliderChild(this, _anim_normal->getSize());
    _stats = Stats::addStatsChild(this);
}

void Enemy::remove()
{
    if (_anim_die->getIsFinish()) {
        _need_remove = true;
    }
}

void Enemy::update(float dt)
{
    Actor::update(dt);
    if (_player->getActive()) {
        aim_target(_player);
        move(dt);
        attack();
    }
    remove();
}

void Enemy::checkState()
{
}

void Enemy::changeState(State state)
{
    if (_current_state == state)
        return;

    _current_anim->setActive(false);
    switch (state) {
    case State::NORMAL:
        _current_anim = _anim_normal;
        break;
    case State::HURT:
        _current_anim = _anim_hurt;
        break;
    case State::DIE:
        _current_anim = _anim_die;
        break;
    default:
        _current_anim = _anim_normal;
        break;
    }
    _current_state = state;
    _current_anim->setActive(true);
}

void Enemy::attack()
{
    if (_collider == nullptr || _player == nullptr || _player->getCollider() == nullptr)
        return;

    if (_collider->isCollidingWith(_player->getCollider())) {
        if (_stats != nullptr && _player->getStats() != nullptr) {
            _player->takeDamage(_stats->getDamage());
        }
    }
}