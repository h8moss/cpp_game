#pragma once
#include "physicsEntity.hpp"

class PhysicsFloor : public PhysicsEntity
{
public:
    PhysicsFloor(std::string, float);
    PhysicsFloor(std::string, float, Vector2, Vector2);

    virtual void setup() override;
    virtual void update() override;
    virtual void draw() const override;
};