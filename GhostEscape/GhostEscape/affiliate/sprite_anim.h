#pragma once

#include <GhostEscape/affiliate/sprite.h>

class SpriteAnim : public Sprite {
    int _current_frame = 0;
    int _total_frames = 0;
    int _fps = 10;
    float _frame_timer = 0.0f;
    bool _is_loop = true;
    bool _is_finish = false;

    virtual void update(float dt) override;
    virtual void render() override;

public:
    static SpriteAnim* addSpriteAnimChild(ObjectScreen* parent, const std::string& file_path, float scale = 1.0f, Anchor anchor = Anchor::CENTER);

    // getters and setters
    int getTotalFrames() { return _total_frames; }
    void setTotalFrames(int total_frames) { _total_frames = total_frames; }
    virtual void setTexture(Texture texture) override;
    int getCurrentFrame() { return _current_frame; }
    void setCurrentFrame(int current_frame) { _current_frame = current_frame; }
    float getFrameTimer() { return _frame_timer; }
    void setFrameTimer(float frame_timer) { _frame_timer = frame_timer; }

    bool getIsLoop() { return _is_loop; }
    void setIsLoop(bool is_loop) { _is_loop = is_loop; }
    bool getIsFinish() { return _is_finish; }
    void setIsFinish(bool is_finish) { _is_finish = is_finish; }
};