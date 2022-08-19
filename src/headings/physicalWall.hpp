#pragma once
#include "physicsEntity.hpp"

class PhysicalWall : public PhysicsEntity
{
public:
    PhysicalWall(std::string id, Vector2 position, Vector2 size);

    virtual void update() override;
    virtual void setup() override;
    virtual void draw() const override;
};