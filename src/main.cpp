#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 700, "POiGK PROJEKT TETRIS");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        
        if (!game.isPaused) 
        {
            if (EventTriggered(game.blockFallDelay))
            {
                game.MoveBlockDown();
            }
        }

        BeginDrawing();
        ClearBackground(lightBlue);
        DrawTextEx(font, "WYNIK", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "NASTEPNY", {330, 175}, 38, 2, WHITE);
        DrawTextEx(font, "Nacisnij P, aby zapauzowac", {10, 630}, 24, 2, WHITE);
        DrawTextEx(font, "POiGK PROJEKT TETRIS - KOZAK & KUBIK", {10, 660}, 24, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "PORAZKA", {340, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, darkGrey);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, darkGrey);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
