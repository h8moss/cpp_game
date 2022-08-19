#pragma once
#include "entity.hpp"
#include "player.hpp"

class CameraController : public Entity
{
private:
    Player *player;

public:
    CameraController(std::string id);
    ~CameraController();

    void setup() override;
    void update() override;
    void draw() const override;
};