#include "headings/physicsEntity.hpp"

#include "raylib.h"

#include "headings/entityManager.hpp"

float PhysicsEntity::gravity{0.2f};

PhysicsEntity::PhysicsEntity(std::string id,
                             float _gravityMultiplier,
                             Vector2 position,
                             Vector2 size)
    : PhysicsEntity(id, _gravityMultiplier, position, size, true, false) {}

PhysicsEntity::PhysicsEntity(
    std::string id,
    float multiplier)
    : PhysicsEntity(id, multiplier, {0, 0}, {1, 1}) {}

PhysicsEntity::PhysicsEntity(std::string id,
                             float _gravityMultiplier,
                             Vector2 position,
                             Vector2 size,
                             bool _isActive,
                             bool _isStatic) : Entity(id, position, size)
{
    isGrounded = false;
    fallingSpeed = 0;
    gravityMultiplier = _gravityMultiplier;
    isActive = _isActive;
    isStatic = _isStatic;
}

void PhysicsEntity::physicsUpdate()
{
    if (isActive)
    {
        if (!isStatic)
        {
            if (!isGrounded)
                fallingSpeed += gravity * gravityMultiplier;

            position = {position.x, position.y + fallingSpeed};
        }
        isGrounded = false;

        for (auto &entity : EntityManager::getInstance()->getEntities())
        {

            PhysicsEntity *pEntity{dynamic_cast<PhysicsEntity *>(entity)};
            if (!isStatic)
            {

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
                            yMovement = collision.height - 0.1f;
                            if (collision.y > position.y)
                            {
                                yMovement *= -1;
                                isGrounded = true;
                                fallingSpeed = 0;
                            }
                        }
                        else
                        {
                            xMovement = collision.height;
                            if (collision.x > position.x)
                            {
                                xMovement *= -1;
                            }
                        }
                        position = {position.x + xMovement, position.y + yMovement};
                    }
                }
            }
        }
    }
}