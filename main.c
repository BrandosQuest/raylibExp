#include <stdio.h>
#include "raylib.h"

int main(void)
{
    int width=800, height=450;
    InitWindow(width, height, "raylib [core] example - basic window");
    SetTargetFPS(60);

    int shuttleXpos=width/2;
    int shuttleWidth=80;
    int shuttleHeight=20;
    bool gameON=false;

    while (!WindowShouldClose())
    {
        //update stuff
        if (!gameON)
        {
            gameON=IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
        }
        shuttleXpos=GetMouseX();

        //draw stuff
        BeginDrawing();
        ClearBackground(DARKGREEN);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawRectangle(shuttleXpos-(shuttleWidth/2), height-shuttleHeight, shuttleWidth, shuttleHeight, BLACK);
        DrawFPS(0,0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
