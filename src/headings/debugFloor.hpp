#pragma once
#include "entity.hpp"

class DebugFloor : public Entity
{
protected:
    Texture2D texture;

public:
    DebugFloor(std::string id, Vector2 pos, Vector2 size);

    virtual void draw() const override;
    virtual void setup() override;
    virtual void update() override;
};