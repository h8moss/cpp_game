#include "raylib.h"

#include <iostream>

#include "headings/entity.hpp"
#include "headings/entityManager.hpp"
#include "headings/physicsEntity.hpp"
#include "headings/player.hpp"
#include "headings/physicsCube.hpp"

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

    EntityManager *em = EntityManager::createInstance(
        {
            new PhysicsCube("cube1", {180, 100}, {50, 50}),
            new PhysicsCube("cube2", {250, 100}, {50, 50}),
            new Player(),
        },
        {
            {screenWidth / 2, screenHeight / 2}, // origin offset to center
            {0, 0},                              // camera position
            0,                                   // camera rotation
            1                                    // camera zoom set to 1
        });

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
        BeginMode2D(em->camera);
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

        EndMode2D();
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