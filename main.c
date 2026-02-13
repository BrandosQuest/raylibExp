/*
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
    bool gameONold=false;
    Vector2 ballVelocity={10,-100};
    Vector2 ballPosition={0,0};
    float ballRadius=10;
    float attenuation=1;

    while (!WindowShouldClose())
    {
        //update stuff
        if (!gameON)
        {
            //gameONold=gameON;
            gameON=IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
            //ballPosition.x= shuttleXpos+(shuttleWidth/2);
            ballPosition.x= shuttleXpos;
            ballPosition.y = height-(shuttleHeight+ballRadius);
        }
        else
        {
            ballPosition.x+=ballVelocity.x*(1.0f/60);
            ballPosition.y+=ballVelocity.y*(1.0f/60);
        }
        shuttleXpos=GetMouseX();


        //draw stuff
        BeginDrawing();
        ClearBackground(DARKGREEN);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawCircle(ballPosition.x ,ballPosition.y ,ballRadius, LIGHTGRAY);
        DrawRectangle(shuttleXpos-(shuttleWidth/2), height-shuttleHeight, shuttleWidth, shuttleHeight, BLACK);
        DrawFPS(0,0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
*/
#include <stdio.h>
#include "raylib.h"

int main(void)
{
    int width=800, height=450;
    InitWindow(width, height, "raylib [core] example - basic window");
    SetTargetFPS(60);

    bool gameON=false;
    int platformHeight=20;
    int platformWidth=80;
    int platformX=0;
    int releaseDamping=10;
    Vector2 pos={0, (float)height-30};
    Vector2 vel={0, 0};
    Vector2 platformVel={0, 0};


    while (!WindowShouldClose())
    {
        //update stuff
        float dt = GetFrameTime();

        platformX=GetMouseX()-platformWidth/2;

        bool previousGameOn=gameON;
        float previousX=pos.x;
        if (!gameON)
        {
            gameON=IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
            pos.x=(float)GetMouseX();
        }
        platformVel.x=(pos.x-previousX)/dt;
        if (previousGameOn!=gameON)
        {
            vel.x=platformVel.x/(float)releaseDamping;
            vel.y=-200;
        }
        if (gameON)
        {
            pos.x+=vel.x*dt;
            pos.y+=vel.y*dt;
            if (pos.x<=0 || pos.x>=(float)width)
            {
                vel.x*=-1;
            }
            if (pos.y<=0)
            {
                vel.y*=-1;
            }
        }
        if (CheckCollisionCircleLine(pos, 10, (Vector2){(float)platformX, (float)(height - platformHeight)}, (Vector2){
                                         (float)(platformX + platformWidth), (float)(height - platformHeight)
                                     }))
        {
            vel.y*=-1;
            int centerX=platformX+platformWidth/2;
            float shuffle=(pos.x-(float)centerX)/(float)platformWidth/2;
            //vel.x*=shuffle*10;
            vel.x+=shuffle*1000;
        }
        if (IsKeyReleased(KEY_R))
        {
            gameON=false;
            pos=(Vector2){0, (float)height-30};
            vel=(Vector2){0, 0};
            platformVel=(Vector2){0, 0};
        }



        //draw stuff
        BeginDrawing();
        ClearBackground(DARKGREEN);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawCircle((int) pos.x,(int) pos.y, 10, BROWN);
        DrawRectangle(platformX, height-platformHeight, platformWidth, platformHeight, BLACK);
        DrawFPS(0,0);
        DrawText(TextFormat("vel.x: %f", vel.x), 0, 20, 20, BLACK);
        DrawText(TextFormat("platformVel.x: %f", platformVel.x), 0, 40, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
