#pragma once
#include "physicsEntity.hpp"

class PhysicsFloor : public PhysicsEntity
{
public:
    PhysicsFloor(std::string);
    PhysicsFloor(std::string, Vector2, Vector2);

    virtual void setup() override;
    virtual void update() override;
    virtual void draw() const override;
};