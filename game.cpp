#include "game.hpp"
#include <assert.h>
#include <array>

void Game::Run() 
{

    // Initialization ---------------------------
    Window Window {1280, 720};                      // Window Dimensins
    int FPS {144};                                  // Frames Per Second
    Game::Initialize(Window, FPS, "Template");      // Create Window

    // create buttons and store in an array
    Button ButtonOne{Window};
    std::array<Button*, 1> Buttons {&ButtonOne};

    // Start Game Loop
    while (!GameShouldClose()) 
    {
        Game::Tick(Window);
        Game::Update();

        for (auto Button:Buttons)
        {
            Button->Tick();
            Button->Draw();
        }
    }

    // Clean-up
    assert(GetWindowHandle());
    CloseWindow();
}

void Game::Initialize(Window Window, int FPS, std::string Title)
{
    assert(!GetWindowHandle());
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    SetExitKey(0);
    InitWindow(Window.x, Window.y, Title.c_str());
    SetTargetFPS(144);
}

bool Game::GameShouldClose()
{
    return WindowShouldClose();
}

void Game::Tick(Window& Window)
{
    // Check if Window has been resized or fullscreened
    Game::CheckScreenSizing(Window);

    // Begin Drawing
    BeginDrawing();
    Update();
    Draw();

    // End Drawing
    EndDrawing();
}

void Game::Update()
{

}

void Game::Draw()
{

    ClearBackground(BLACK);
}

void Game::CheckScreenSizing(Window& Window)
{
    // set window.x / window.y to resized dimensions
    if (IsWindowResized()) 
    {
        Window.x = GetScreenWidth();
        Window.y = GetScreenHeight();
    }

    // check for alt + enter [FULLSCREN]
    if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
    {
        SetFullScreen(Window);
    }
}

void Game::SetFullScreen(Window& Window)
{
    // see what display we are on right now
    int display = GetCurrentMonitor();

    if (IsWindowFullscreen()) 
    {
        // if we are full screen, then go back to the windowed size
        ToggleFullscreen();                  
        SetWindowSize(Window.x, Window.y); 
    }
    else
    {                                        
        // if we are not full screen, set the window size to match the monitor we are on
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        ToggleFullscreen();
    }
}