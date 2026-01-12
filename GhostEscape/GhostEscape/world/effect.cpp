#include <GhostEscape/core/scene.h>
#include <GhostEscape/world/effect.h>

Effect* Effect::addEffectChild(Object* parent, const std::string file_path, glm::vec2 pos, float scale, ObjectWorld* next_object)
{
    Effect* effect = new Effect();
    effect->init();
    effect->_spriteAnim = SpriteAnim::addSpriteAnimChild(effect, file_path, scale);
    effect->_spriteAnim->setIsLoop(false);
    effect->setPosition(pos);
    effect->setNextObject(next_object);
    if (parent != nullptr)
        parent->safeAddChild(effect);
    return effect;
}

void Effect::update(float dt)
{
    ObjectWorld::update(dt);
    checkFinish();
}

void Effect::checkFinish()
{
    if (_spriteAnim->getIsFinish()) {
        _need_remove = true;
        if (_next_object != nullptr) {
            game.getCurrentScene()->safeAddChild(_next_object);
        }
    }
}