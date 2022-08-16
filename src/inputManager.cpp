#include "headings/inputManager.hpp"

#include "raylib.h"

int InputManager::getHorizontalInput()
{
    return getAxisInput(GAMEPAD_AXIS_LEFT_X,
                        GAMEPAD_BUTTON_LEFT_FACE_RIGHT,
                        GAMEPAD_BUTTON_LEFT_FACE_LEFT,
                        KEY_D, KEY_A);
}

int InputManager::getVerticalInput()
{
    return getAxisInput(GAMEPAD_AXIS_LEFT_Y,
                        GAMEPAD_BUTTON_LEFT_FACE_DOWN,
                        GAMEPAD_BUTTON_LEFT_FACE_UP,
                        KEY_S, KEY_W);
}

int InputManager::getAxisInput(int axis, int positiveButton, int negativeButton, int positiveKey, int negativeKey)
{
    int result = 0;
    if (IsGamepadAvailable(0))
    {
        float axisMovement = GetGamepadAxisMovement(0, axis);
        if (IsGamepadButtonDown(0, positiveButton))
            axisMovement += 1;
        if (IsGamepadButtonDown(0, negativeButton))
            axisMovement -= 1;

        result = axisMovement > 0.2f
                     ? 1
                 : axisMovement < -0.2f
                     ? -1
                     : 0;
    }
    else
    {
        if (IsKeyDown(positiveKey))
            result += 1;
        if (IsKeyDown(negativeKey))
            result -= 1;
    }

    return result;
}

bool InputManager::getJump()
{
    return IsKeyPressed(KEY_SPACE) || (IsGamepadAvailable(0) && IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN));
}

bool InputManager::getSpecial1Pressed()
{
    return IsKeyPressed(KEY_E) || (IsGamepadAvailable(0) && IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1));
}