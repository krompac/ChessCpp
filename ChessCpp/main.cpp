#include <iostream>
#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Window");

    SetTargetFPS(60);               

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello there", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }


    CloseWindow();

    return 0;
}