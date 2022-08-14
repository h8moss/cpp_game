#pragma once
#include "entity.hpp"

class PhysicsEntity : public Entity
{

protected:
    float fallingSpeed;
    bool isGrounded;

    static float gravity;

public:
    PhysicsEntity(std::string, float);
    PhysicsEntity(std::string, float, Vector2, Vector2);
    PhysicsEntity(std::string, float, Vector2, Vector2, bool, bool);

    void physicsUpdate();
    float gravityMultiplier;
    bool isActive;
    bool isStatic;
};