#pragma once
#include "raylib.h"

#include <string>

class Entity
{
protected:
    Vector2 position;
    Vector2 size;
    std::string uniqueId;

public:
    Entity(std::string, Vector2, Vector2);
    Entity(std::string);
    ~Entity();

    virtual void update() = 0;
    virtual void setup() = 0;
    virtual void draw() const = 0;

    std::string getUniqueId();

    Rectangle getBoundingBox() const;
};