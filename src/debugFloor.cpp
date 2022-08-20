#include "headings/debugFloor.hpp"

DebugFloor::DebugFloor(std::string id, Vector2 pos, Vector2 size) : Entity(id, pos, size) {}

void DebugFloor::update() {}
void DebugFloor::setup()
{
    texture = LoadTexture("assets/grid.png");
}

void DebugFloor::draw() const
{
    float textureXCount = (float)size.x / texture.width;
    float textureYCount = (float)size.y / texture.height;

    float xReverseCounter{textureXCount};
    int xCounter{};
    while (xReverseCounter >= 0)
    {
        int yCounter{};
        float yReverseCounter{textureYCount};

        while (yReverseCounter >= 0)
        {
            DrawTexture(texture, position.x + xCounter * texture.width, position.y + yCounter * texture.height, WHITE);

            yReverseCounter--;
            yCounter++;
        }

        xReverseCounter--;
        xCounter++;
    }
}