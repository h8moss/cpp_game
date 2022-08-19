#pragma once
#include "entity.hpp"
#include "player.hpp"

class CameraController : public Entity
{
private:
    Player *player;
    Rectangle cameraBounds;

    Vector2 bindCameraLocation(Vector2 cameraLocation, Vector2 cameraSize);

public:
    CameraController(std::string id, Rectangle cameraBounds);
    ~CameraController();

    void setup() override;
    void update() override;
    void draw() const override;
};