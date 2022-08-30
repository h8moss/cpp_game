#include "headings/player.hpp"

#include "raylib.h"

#include "headings/inputManager.hpp"
#include "headings/vectorOperations.hpp"
#include "headings/entityManager.hpp"

// TODO: Implement delta time everywhere

std::string Player::playerID = "Player";

Player::Player() : PhysicsEntity(playerID, {0, 0}, {40, 40})
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
    Vector2 movement{
        static_cast<float>(InputManager::getHorizontalInput()),
        static_cast<float>(InputManager::getVerticalInput())};

    if (dashTimer <= 0)
    {
        move(movement, movementSpeed);
        if (InputManager::getDash())
        {
            dashTimer = dashDuration;
            dashDirection = movement;
        }
    }
    else
    {
        move(dashDirection, dashSpeed);
        dashTimer--;
    }
}

void Player::move(Vector2 direction, float speed)
{
    direction = VectorOP::normalize(direction);

    if ((direction.x > 0 && !canMoveRight()) || (direction.x < 0 && !canMoveLeft()))
    {
        direction.x = 0;
    }
    if ((direction.y > 0 && !canMoveDown()) || (direction.y < 0 && !canMoveUp()))
    {
        direction.y = 0;
    }

    position = VectorOP::add(position, VectorOP::multiply(direction, speed));
}

void Player::draw() const
{
    DrawCircle(position.x + size.x / 2, position.y + size.y / 2, size.x / 2, PURPLE);
}

void Player::debugDraw() const
{
    std::string txt = "(" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";
    Vector2 position{GetScreenToWorld2D({20, 40}, EntityManager::getInstance()->camera)};

    DrawText(txt.c_str(), position.x, position.y, 20, BLACK);
}