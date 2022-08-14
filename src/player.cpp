#include "headings/player.hpp"

#include "raylib.h"

#include "headings/inputManager.hpp"

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
    if (isGrounded && InputManager::getJump())
    {
        fallingSpeed = -jumpForce;
    }

    float xMovement{InputManager::getHorizontalInput() * movementSpeed};

    position = {position.x + xMovement, position.y};
}

void Player::draw() const
{
    DrawEllipse(position.x + size.x / 2, position.y + size.y / 2, (float)size.x / 2, (float)size.y / 2, PURPLE);
}