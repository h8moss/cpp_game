#pragma once
#include "entity.hpp"

class PhysicsEntity : public Entity
{

protected:
    bool isTouchingT;
    bool isTouchingL;
    bool isTouchingD;
    bool isTouchingR;

    bool canMoveT;
    bool canMoveL;
    bool canMoveD;
    bool canMoveR;

    bool isActive;
    bool isStatic;

public:
    PhysicsEntity(std::string id);
    PhysicsEntity(std::string id, Vector2 position, Vector2 size);
    PhysicsEntity(std::string id, Vector2 position, Vector2 size, bool isStatic, bool isActive);

    void physicsUpdate();

    bool hasCollision() const;

    bool getCanMoveT();
    bool getCanMoveL();
    bool getCanMoveD();
    bool getCanMoveR();
    bool getIsActive();
    bool getIsStatic();
};