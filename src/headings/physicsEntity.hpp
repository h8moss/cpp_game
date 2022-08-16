#pragma once
#include "entity.hpp"

class PhysicsEntity : public Entity
{

protected:
    bool isActive;
    bool isStatic;

    PhysicsEntity *collisionTop;
    PhysicsEntity *collisionLeft;
    PhysicsEntity *collisionDown;
    PhysicsEntity *collisionRight;

public:
    PhysicsEntity(std::string id);
    PhysicsEntity(std::string id, Vector2 position, Vector2 size);
    PhysicsEntity(std::string id, Vector2 position, Vector2 size, bool isStatic, bool isActive);

    void physicsUpdate();

    bool hasCollision() const;

    // Holy shit TL;DR stands for Top, Left, Down, Right.
    bool isTouchingT() const;
    bool isTouchingL() const;
    bool isTouchingD() const;
    bool isTouchingR() const;

    bool canMoveUp() const;
    bool canMoveLeft() const;
    bool canMoveDown() const;
    bool canMoveRight() const;
};