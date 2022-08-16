#include "headings/player.hpp"

#include "raylib.h"

#include "headings/inputManager.hpp"

// TODO: Implement delta time everywhere

Player::Player() : PhysicsEntity("player", {500, 100}, {40, 40})
{
    movementSpeed = 5.0f;
    jumpForce = 5.0f;
}

void Player::setup() {}

void Player::update()
{
    float xMovement{InputManager::getHorizontalInput() * movementSpeed};
    float yMovement{InputManager::getVerticalInput() * movementSpeed};

    if (xMovement > 0 && !canMoveRight())
    {
        xMovement = 0;
    }
    else if (xMovement < 0 && !canMoveLeft())
    {
        xMovement = 0;
    }
    if (yMovement > 0 && !canMoveDown())
    {
        yMovement = 0;
    }
    else if (yMovement < 0 && !canMoveUp())
    {
        yMovement = 0;
    }

    position = {position.x + xMovement, position.y + yMovement};
}

void Player::draw() const
{
    DrawEllipse(position.x + size.x / 2, position.y + size.y / 2, (float)size.x / 2, (float)size.y / 2, PURPLE);
}