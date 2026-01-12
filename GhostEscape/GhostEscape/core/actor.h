#pragma once

#include <GhostEscape/core/object_world.h>
class Stats;
class Actor : public ObjectWorld {
protected:
    Stats* _stats = nullptr;
    glm::vec2 _velocity = glm::vec2 { 0.0f, 0.0f };
    float _max_speed = 100.0f;

public:
    void move(float dt);
    void takeDamage(float damage);
    bool getIsAlive();

    // getters and setters
    glm::vec2 getVelocity() { return _velocity; }
    void setVelocity(glm::vec2 velocity) { _velocity = velocity; }
    
    float getMaxSpeed() { return _max_speed; }
    void setMaxSpeed(float max_speed) { _max_speed = max_speed; }

    Stats* getStats() { return _stats; }
    void setStats(Stats* stats) { _stats = stats; }
};