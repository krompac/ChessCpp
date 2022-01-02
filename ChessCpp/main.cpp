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

    Font letterFont = GetFontDefault();

    InitWindow(screenWidth, screenHeight, "Chess");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        int x = initialXPos;
        int y = initialYPos;

        ClearBackground(background);

        DrawRectangleLinesEx(rec, 6, WHITE);

        int a = 8;

        for (int i = 1; i <= numberOfSquares * 8; i++)
        {
            std::string b;
            b.push_back('0' + a);

            if (i % 2 == 0)
            {
                DrawRectangle(x, y, squareSide, squareSide, lightColor);
            }
            else
            {
                DrawRectangle(x, y, squareSide, squareSide, darkColor);
            }

            DrawTextEx(GetFontDefault(), b.c_str(), { initialXPos - 30.f, y + squareSide / 2 - 12.f }, 26.f, 1.f, letterColor);
            
            if (i % 8 == 0) 
            {
                x = initialXPos;
                y += squareSide;

                std::swap(lightColor, darkColor);

                a--;
            }
            else
            {
                x += squareSide;
            }
        }

        x = initialXPos;
        y += 10;
        

        for (int i = 0; i < 8; i++)
        {
            std::string b;
            b.push_back('a' + i);
            int textSize = MeasureText(b.c_str(), 26);


            DrawTextEx(GetFontDefault(), b.c_str(), { x + squareSide / 2.f - textSize / 2.f, (float) y }, 26.f, 1.f, letterColor);
            x += squareSide;
        }

        EndDrawing();
    }


    CloseWindow();

    return 0;
}