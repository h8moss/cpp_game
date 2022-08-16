#include "headings/physicsFloor.hpp"

PhysicsFloor::PhysicsFloor(std::string id) : PhysicsEntity(id) {}
PhysicsFloor::PhysicsFloor(std::string id, Vector2 position, Vector2 size) : PhysicsEntity(id, position, size, true, true) {}

void PhysicsFloor::setup() {}
void PhysicsFloor::update() {}
void PhysicsFloor::draw() const
{
    DrawRectangleRec(getBoundingBox(), YELLOW);
}