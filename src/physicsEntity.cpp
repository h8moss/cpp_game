#include "headings/physicsEntity.hpp"

#include "raylib.h"

#include "headings/entityManager.hpp"

PhysicsEntity::PhysicsEntity(std::string id,
                             Vector2 position,
                             Vector2 size)
    : PhysicsEntity(id, position, size, true, false) {}

PhysicsEntity::PhysicsEntity(std::string id) : PhysicsEntity(id, {0, 0}, {1, 1}) {}

PhysicsEntity::PhysicsEntity(std::string id,
                             Vector2 position,
                             Vector2 size,
                             bool _isActive,
                             bool _isStatic) : Entity(id, position, size)
{
    isActive = _isActive;
    isStatic = _isStatic;

    collisionTop = nullptr;
    collisionLeft = nullptr;
    collisionDown = nullptr;
    collisionRight = nullptr;
}

void PhysicsEntity::physicsUpdate()
{
    if (isActive)
    {
        collisionTop = nullptr;
        collisionLeft = nullptr;
        collisionDown = nullptr;
        collisionRight = nullptr;

        if (!isStatic)
        {
            for (auto &entity : EntityManager::getInstance()->getEntities())
            {
                PhysicsEntity *pEntity{dynamic_cast<PhysicsEntity *>(entity)};

                if (entity->getUniqueId() != uniqueId && pEntity != nullptr && pEntity->isActive)
                {
                    if (CheckCollisionRecs(getBoundingBox(), pEntity->getBoundingBox()))
                    {
                        Rectangle collision{
                            GetCollisionRec(getBoundingBox(), pEntity->getBoundingBox())};
                        float yMovement{};
                        float xMovement{};
                        if (collision.height <= collision.width)
                        {
                            yMovement = collision.height - 0.01f;
                            if (collision.y > position.y)
                            {
                                yMovement *= -1;
                                collisionDown = pEntity;
                            }
                            else
                            {
                                collisionTop = pEntity;
                            }
                        }
                        else
                        {
                            xMovement = collision.width - 0.01f;
                            if (collision.x > position.x)
                            {
                                xMovement *= -1;
                                collisionRight = pEntity;
                            }
                            else
                            {
                                collisionLeft = pEntity;
                            }
                        }
                        position = {position.x + xMovement, position.y + yMovement};
                    }
                }
            }
        }
    }
}

bool PhysicsEntity::hasCollision() const
{
    return isTouchingT() || isTouchingL() || isTouchingD() || isTouchingR();
}

bool PhysicsEntity::isTouchingT() const { return collisionTop != nullptr; }
bool PhysicsEntity::isTouchingL() const { return collisionLeft != nullptr; }
bool PhysicsEntity::isTouchingD() const { return collisionDown != nullptr; }
bool PhysicsEntity::isTouchingR() const { return collisionRight != nullptr; }

bool PhysicsEntity::canMoveUp() const
{
    return isStatic
               ? false
               : (isTouchingT()
                      ? collisionTop->canMoveUp()
                      : true);
}

bool PhysicsEntity::canMoveLeft() const
{
    return isStatic
               ? false
               : (isTouchingL()
                      ? collisionLeft->canMoveLeft()
                      : true);
}

bool PhysicsEntity::canMoveDown() const
{
    return isStatic
               ? false
               : (isTouchingD()
                      ? collisionDown->canMoveDown()
                      : true);
}

bool PhysicsEntity::canMoveRight() const
{
    return isStatic
               ? false
               : (isTouchingR()
                      ? collisionRight->canMoveRight()
                      : true);
}