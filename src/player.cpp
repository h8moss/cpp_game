#include "headings/player.hpp"

#include "raylib.h"

// TODO: Implement delta time everywhere

Player *Player::instance = nullptr;

Player::Player() : PhysicsEntity("player", 1, {500, 100}, {40, 80})
{
    movementSpeed = 5.0f;
    jumpForce = 5.0f;
}

Player *Player::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Player();
    }

    return instance;
}

void Player::setup() {}

void Player::update()
{
    if (isGrounded && IsKeyPressed(KEY_SPACE))
    {
        fallingSpeed = -jumpForce;
        isGrounded = false;
    }

    float xMovement{};
    if (IsKeyDown(KEY_A))
    {
        xMovement = -movementSpeed;
    }
    else if (IsKeyDown(KEY_D))
    {
        xMovement = movementSpeed;
    }

    position = {position.x + xMovement, position.y};
}

void Player::draw() const
{
    DrawEllipse(position.x + size.x / 2, position.y + size.y / 2, (float)size.x / 2, (float)size.y / 2, PURPLE);
}