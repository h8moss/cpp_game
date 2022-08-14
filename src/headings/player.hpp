#pragma once
#include "physicsEntity.hpp"

class Player : public PhysicsEntity
{
private:
    static Player *instance;
    Player();

protected:
    float movementSpeed;
    float jumpForce;

public:
    static Player *getInstance();

    virtual void setup() override;
    virtual void update() override;
    virtual void draw() const override;
};