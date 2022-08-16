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

    isTouchingT = false;
    isTouchingL = false;
    isTouchingD = false;
    isTouchingR = false;
}

void PhysicsEntity::physicsUpdate()
{
    if (isActive)
    {
        isTouchingT = false;
        isTouchingL = false;
        isTouchingD = false;
        isTouchingR = false;

        if (!isStatic)
        {
            for (auto &entity : EntityManager::getInstance()->getEntities())
            {
                PhysicsEntity *pEntity{dynamic_cast<PhysicsEntity *>(entity)};

                if (entity->getUniqueId() != uniqueId && pEntity != nullptr && pEntity->isActive)
                {
                    if (CheckCollisionRecs(getBoundingBox(), entity->getBoundingBox()))
                    {
                        Rectangle collision{
                            GetCollisionRec(getBoundingBox(), entity->getBoundingBox())};
                        float yMovement{};
                        float xMovement{};
                        if (collision.height <= collision.width)
                        {
                            yMovement = collision.height - 0.01f;
                            if (collision.y > position.y)
                            {
                                yMovement *= -1;
                                isTouchingD = true;
                            }
                            else
                            {
                                isTouchingT = true;
                            }
                        }
                        else
                        {
                            xMovement = collision.width - 0.01f;
                            if (collision.x > position.x)
                            {
                                xMovement *= -1;
                                isTouchingR = true;
                            }
                            else
                            {
                                isTouchingL = true;
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
    return isTouchingT || isTouchingL || isTouchingD || isTouchingR;
}