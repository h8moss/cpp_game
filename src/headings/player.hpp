#pragma once
#include "physicsEntity.hpp"

class Player : public PhysicsEntity
{
private:
    float dashSpeed;
    int dashDuration;
    int dashTimer;
    Vector2 dashDirection;

protected:
    float movementSpeed;

    void move(Vector2 direction, float speed);

public:
    Player();

    virtual void setup() override;
    virtual void update() override;
    virtual void draw() const override;
};