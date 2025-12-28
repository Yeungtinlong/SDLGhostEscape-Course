#pragma once

#include <GhostEscape/affiliate/sprite.h>

class SpriteAnim : public Sprite {
    int _current_frame = 0;
    int _total_frames = 0;
    int _fps = 10;
    float _frame_timer = 0.0f;

    virtual void update(float dt) override;
    virtual void render() override;

public:
    static SpriteAnim* addSpriteAnimChild(ObjectScreen* parent, const std::string& file_path, const glm::vec2& offset, float scale = 1.0f);

    // getters and setters
    int getTotalFrames() { return _total_frames; }
    void setTotalFrames(int total_frames) { _total_frames = total_frames; }
    virtual void setTexture(Texture texture) override;
    int getCurrentFrame() { return _current_frame; }
    void setCurrentFrame(int current_frame) { _current_frame = current_frame; }
    float getFrameTimer() { return _frame_timer; }
    void setFrameTimer(float frame_timer) { _frame_timer = frame_timer; }
};