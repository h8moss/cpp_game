#include "headings/player.hpp"

#include "raylib.h"

#include "headings/inputManager.hpp"
#include "headings/vectorOperations.hpp"

// TODO: Implement delta time everywhere

Player::Player() : PhysicsEntity("player", {500, 100}, {40, 40})
{
    dashSpeed = 25.0f;
    dashDuration = 6; // tenth of a second
    dashTimer = 0;
    dashDirection = {0, 0};

    movementSpeed = 5.0f;
}

void Player::setup() {}

void Player::update()
{
    Vector2 movement{(float)InputManager::getHorizontalInput(), (float)InputManager::getVerticalInput()};

    if (movement.x > 0 && !canMoveRight())
    {
        movement.x = 0;
    }
    else if (movement.x < 0 && !canMoveLeft())
    {
        movement.x = 0;
    }
    if (movement.y > 0 && !canMoveDown())
    {
        movement.y = 0;
    }
    else if (movement.y < 0 && !canMoveUp())
    {
        movement.y = 0;
    }

    position = VectorOP::add(position, VectorOP::multiply(movement, movementSpeed));

    if (IsKeyPressed(KEY_SPACE) && dashTimer <= 0)
    {
        dashTimer = dashDuration;
        dashDirection = movement;
    }

    if (--dashTimer > 0)
    {
        position = VectorOP::add(position, VectorOP::multiply(VectorOP::normalize(dashDirection), dashSpeed));
    }
}

void Player::draw() const
{
    DrawEllipse(position.x + size.x / 2, position.y + size.y / 2, (float)size.x / 2, (float)size.y / 2, dashTimer == 0 ? PURPLE : GREEN);

    // DEBUG
    std::string positionStr = "[" + std::to_string(position.x) + ", " + std::to_string(position.y) + "]";
    DrawText(positionStr.c_str(), 10, 10, 20, BLACK);
}