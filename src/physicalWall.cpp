#include "headings/physicalWall.hpp"

PhysicalWall::PhysicalWall(std::string id, Vector2 position, Vector2 size)
    : PhysicsEntity(id, position, size, true, true) {}

void PhysicalWall::update()
{
}
void PhysicalWall::setup()
{
}
void PhysicalWall::draw() const
{
    DrawRectangle(position.x, position.y, size.x, size.y, BLACK);
}
