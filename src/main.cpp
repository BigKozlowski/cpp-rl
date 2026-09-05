#include <raylib.h>
#include "./Game.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    Game game;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    game.init();
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        game.step();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}