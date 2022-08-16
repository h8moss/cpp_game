#include "headings/physicsCube.hpp"
#include "raylib.h"

#include "headings/physicsEntity.hpp"
#include "headings/entityManager.hpp"

PhysicsCube::PhysicsCube(std::string id) : PhysicsEntity(id) {}
PhysicsCube::PhysicsCube(std::string id, Vector2 position, Vector2 size) : PhysicsEntity(id, position, size) {}

void PhysicsCube::draw() const
{
    DrawRectangleRec(getBoundingBox(), hasCollision() ? GREEN : RED);
}
void PhysicsCube::setup() {}

void PhysicsCube::update() {}