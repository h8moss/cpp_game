#pragma once

class InputManager
{
private:
    static int getAxisInput(int axis, int positiveButton, int negativeButton, int positiveKey, int negativeKey);

public:
    static int getHorizontalInput();
    static int getVerticalInput();
    static bool getJump();

    static bool getSpecial1Pressed();
};