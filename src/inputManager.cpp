#include "headings/inputManager.hpp"

#include "raylib.h"

int InputManager::getHorizontalInput()
{
    int result = 0;

    if (IsGamepadAvailable(0))
    {
        float axisMovement = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
        result = axisMovement > 0.2f
                     ? 1
                 : axisMovement < -0.2f
                     ? -1
                     : 0;
    }
    else
    {
        if (IsKeyDown(KEY_A))
            result -= 1;

        if (IsKeyDown(KEY_D))
            result += 1;
    }
    return result;
}

bool InputManager::getJump()
{
    return IsKeyPressed(KEY_SPACE) || IsGamepadAvailable(0) && IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
}