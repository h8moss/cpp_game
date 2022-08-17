#include "raylib.h"

#include <iostream>

#include "headings/entity.hpp"
#include "headings/entityManager.hpp"
#include "headings/physicsEntity.hpp"

//------------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth{800};
    const int screenHeight{450};

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    EntityManager *em = EntityManager::getInstance();

    for (Entity *e : em->getEntities())
    {
        e->setup();
    }

    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Physics Update
        //----------------------------------------------------------------------------------
        for (Entity *e : em->getEntities())
        {
            PhysicsEntity *pe{dynamic_cast<PhysicsEntity *>(e)};
            if (pe != nullptr)
            {
                pe->physicsUpdate();
            }
        }

        // Update
        //----------------------------------------------------------------------------------
        for (Entity *e : em->getEntities())
        {
            e->update();
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(WHITE);

        for (Entity *e : em->getEntities())
        {
            e->draw();
        }

// DEBUG DRAW
#ifdef DEBUG
        DrawText("DEBUG", 10, 10, 20, RED);
#endif
        // ----------------------------------------------------------------------------------

        EndDrawing();
        //-----------------------------------------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    em->destroyInstance();
    //---------------------------------------------------------------------------------------

    return 0;
}