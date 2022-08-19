#include "headings/entity.hpp"

Entity::Entity(std::string _uniqueId, Vector2 _position, Vector2 _size)
{
    uniqueId = _uniqueId;
    position = _position;
    size = _size;
}

Entity::Entity(std::string _uniqueId)
{
    uniqueId = _uniqueId;
    position = {0, 0};
    size = {1, 1};
}

Entity::~Entity() {}

std::string Entity::getUniqueId()
{
    return uniqueId;
}

Rectangle Entity::getBoundingBox() const
{
    return {position.x, position.y, size.x, size.y};
}

Vector2 Entity::getPosition() const
{
    return position;
}

Vector2 Entity::getSize() const
{
    return size;
}

void Entity::debugDraw() const {}