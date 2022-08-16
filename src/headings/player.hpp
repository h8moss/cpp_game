#pragma once
#include "physicsEntity.hpp"

class Player : public PhysicsEntity
{
private:
protected:
    float movementSpeed;
    float jumpForce;

public:
    Player();

    virtual void setup() override;
    virtual void update() override;
    virtual void draw() const override;
};