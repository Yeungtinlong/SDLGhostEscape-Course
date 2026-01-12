#pragma once

#include <GhostEscape/affiliate/sprite_anim.h>
#include <GhostEscape/core/object_world.h>
#include <string>

class Effect : public ObjectWorld {
    SpriteAnim* _spriteAnim = nullptr;
    ObjectWorld* _next_object = nullptr; // next object to be created after this effect is finished

public:
    static Effect* addEffectChild(Object* parent, const std::string file_path, glm::vec2 pos, float scale = 1.0f, ObjectWorld* next_object = nullptr);

    virtual void update(float dt) override;
    // getters and setters
    SpriteAnim* getSpriteAnim() { return _spriteAnim; }
    void setSpriteAnim(SpriteAnim* spriteAnim) { _spriteAnim = spriteAnim; }

    ObjectWorld* getNextObject() { return _next_object; }
    void setNextObject(ObjectWorld* next_object) { _next_object = next_object; }

private:
    void checkFinish();
};