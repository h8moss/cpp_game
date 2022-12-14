#include "raylib.h"

#include <iostream>

#include "headings/entity.hpp"
#include "headings/entityManager.hpp"
#include "headings/physicsEntity.hpp"
#include "headings/player.hpp"
#include "headings/physicsCube.hpp"
#include "headings/cameraController.hpp"
#include "headings/physicalWall.hpp"
#include "headings/constants.hpp"
#include "headings/debugFloor.hpp"

#include "headings/messageBus.hpp"

//------------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(constants::SCREEN_WIDTH, constants::SCREEN_HEIGHT, constants::WINDOW_TITLE);

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    EntityManager *em = EntityManager::createInstance(
        {
            new MessageBus(),
            new DebugFloor("FLOOR", {-750, -750}, {1500, 1500}),
            new Player(),
            //  new PhysicalWall("wallL", {-900, -800}, {200, 1500}),
            //  new PhysicalWall("wallT", {-800, -650}, {1600, 200}),
            //  new PhysicalWall("wallRHigh", {750, -800}, {200, 700}),
            //  new PhysicalWall("wallRLow", {700, 100}, {200, 700}),
            //  new PhysicalWall("wallD", {-800, 700}, {1500, 200}),
            new CameraController("cameraController", {-800, -500, 1600, 1000}),
        },
        {
            {
                static_cast<float>(constants::SCREEN_WIDTH) / 2,  // offset x from top left to center
                static_cast<float>(constants::SCREEN_HEIGHT) / 2, // offset y from top left to center
            },
            {0, 0}, // camera position
            0,      // camera rotation
            1       // camera zoom set to 1
        });

    em->createWalls({1600, 1000}, 50, 150);

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
        for (Entity *e : em->getEntities())
        {
            e->debugDraw();
        }
        Vector2 fpsPos = GetScreenToWorld2D({10, 10}, em->camera);
        DrawFPS(fpsPos.x, fpsPos.y);

        DrawRectangle(0, 0, 100, 100, RED);
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