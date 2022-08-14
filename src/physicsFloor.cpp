#include "headings/physicsFloor.hpp"

PhysicsFloor::PhysicsFloor(std::string id, float gravityMultiplier) : PhysicsEntity(id, gravityMultiplier) {}
PhysicsFloor::PhysicsFloor(std::string id, float gravityMultiplier, Vector2 position, Vector2 size) : PhysicsEntity(id, gravityMultiplier, position, size, true, true) {}

void PhysicsFloor::setup() {}
void PhysicsFloor::update() {}
void PhysicsFloor::draw() const
{
    DrawRectangleRec(getBoundingBox(), YELLOW);
}