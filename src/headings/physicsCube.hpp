#pragma once
#include "physicsEntity.hpp"

class PhysicsCube : public PhysicsEntity
{
public:
    PhysicsCube(std::string);
    PhysicsCube(std::string, Vector2, Vector2);

    virtual void setup() override;
    virtual void update() override;
    virtual void draw() const override;
};
