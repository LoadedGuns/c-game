/*
Game coded in C using Raylib for visual and audio.
LEAD DEVELOPER: James Sweetsir
Project Start Date: 03/22/2026
*/

#include "raylib.h"
#include "resource_dir.h"

int main(void)
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(1280, 800, "Game made in C with Raylib audio/visual engine");

    SearchAndSetResourceDir("resources");

    //Texture Variables
    Texture2D player = LoadTexture("wabbit_alpha.png");
    Vector2 pos = { 400, 250 };
    float speed = 125.0f;
    SetTargetFPS(60);

    //Audio Variables
    InitAudioDevice();
    SetMasterVolume(2);

    Music main = LoadMusicStream("Scape Main.mp3");
    PlayMusicStream(main);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // UPDATE
        if (IsKeyDown(KEY_RIGHT)) pos.x += speed * dt;
        if (IsKeyDown(KEY_LEFT))  pos.x -= speed * dt;
        if (IsKeyDown(KEY_UP))    pos.y -= speed * dt;
        if (IsKeyDown(KEY_DOWN))  pos.y += speed * dt;

        // DRAW
        BeginDrawing();
        ClearBackground(BLACK);

        UpdateMusicStream(main);
        DrawText("James Sweetsir's Game Made in C with Raylib", 200, 200, 20, WHITE);
        DrawTexture(player, (int)pos.x, (int)pos.y, WHITE);

        EndDrawing();
    }

    UnloadTexture(player);
    CloseWindow();
    return 0;
}