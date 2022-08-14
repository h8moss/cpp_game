#include "headings/physicsCube.hpp"
#include "raylib.h"

#include "headings/physicsEntity.hpp"
#include "headings/entityManager.hpp"

PhysicsCube::PhysicsCube(std::string id, float gravityMultiplier) : PhysicsEntity(id, gravityMultiplier) {}
PhysicsCube::PhysicsCube(std::string id, float gravityMultiplier, Vector2 position, Vector2 size) : PhysicsEntity(id, gravityMultiplier, position, size) {}

void PhysicsCube::draw() const
{
    DrawRectangleRec(getBoundingBox(), isGrounded ? GREEN : RED);
}
void PhysicsCube::setup() {}

void PhysicsCube::update() {}