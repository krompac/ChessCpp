#include <iostream>
#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int numberOfSquares = 8;

    int squareSide = 85;

    int initialXPos = (screenWidth - (squareSide * 8)) / 2;
    int initialYPos = (screenHeight - (squareSide * 8)) / 2;

    Rectangle rec = { initialXPos - 6.f, initialYPos - 6.f, squareSide * 8 + 12.f, squareSide * 8 + 12.f };

    Color lightColor = { 226, 184, 126, 255 };
    Color darkColor = { 143, 87, 54, 255 };

    Color letterColor = { 238, 229, 217, 255 };

    Color background = { 163,78,37,255 };

    InitWindow(screenWidth, screenHeight, "Chess");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        int x = initialXPos;
        int y = initialYPos;

        ClearBackground(background);

        DrawRectangleLinesEx(rec, 6, WHITE);

        for (int i = 1; i <= numberOfSquares * 8; i++)
        {
            if (i % 2 == 0)
            {
                DrawRectangle(x, y, squareSide, squareSide, lightColor);
            }
            else
            {
                DrawRectangle(x, y, squareSide, squareSide, darkColor);
            }
            
            if (i % 8 == 0) 
            {
                x = initialXPos;
                y += squareSide;

                std::swap(lightColor, darkColor);
            }
            else
            {
                x += squareSide;
            }
        }

        EndDrawing();
    }


    CloseWindow();

    return 0;
}