#include "game.hpp"
#include <assert.h>
#include <array>
#include <vector>

void Game::Run() 
{

    // Initialization ---------------------------
    Window Window {1280, 720};                      // Window Dimensions
    int FPS {144};                                  // Frames Per Second
    Game::Initialize(Window, FPS, "Template");      // Create Window

    // create buttons and store in an array
    Button ButtonOne{Window, Vector2{.5f, .5f}, Rectangle{0.f,0.f,160.f,160.f},
                     LoadTexture("images/poopdragon-0.png"),
                     LoadTexture("images/poopdragon-2.png"),
                     LoadTexture("images/poopdragon-3.png")};
    std::array<Button*, 1> MainMenu {&ButtonOne};
    std::array<std::array<Button*, 1>, 1> Buttons{MainMenu};


    // Start Game Loop
    while (!WindowShouldClose()) 
    {
        Game::Tick(Window, Buttons);
    }

    // Clean-up
    assert(GetWindowHandle());
    CloseWindow();
}

// Set the Game's window configurations
void Game::Initialize(Window& Window, int FPS, std::string Title)
{
    assert(!GetWindowHandle());
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    SetExitKey(0);
    InitWindow(Window.x, Window.y, Title.c_str());
    SetTargetFPS(144);
}

void Game::Tick(Window& Window, std::array<std::array<Button*, 1>, 1>& Buttons)
{
    // Check if Window has been resized or fullscreened
    Game::CheckScreenSizing(Window);

    // Begin Drawing
    BeginDrawing();
    ClearBackground(BLACK);
    Game::Update(Buttons);
    Game::Draw(Buttons);

    // End Drawing
    EndDrawing();
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

template <typename T>
void Game::Update(std::array<std::array<T*, 1>, 1>& Container)
{
    for (auto Set:Container) 
        for (auto Element:Set)
        {
            Element->Tick();
        }
}

void Game::Draw(std::array<std::array<Button*, 1>, 1>& Buttons)
{
    for (auto Set:Buttons)
        for (auto Button:Set)
        {
            Button->Draw();
            if (Button->isActivated())
            {
                DrawText(TextFormat("Button: \"I am active\" \n"), 20, 20, 20, WHITE);
            }
            else
            {
                DrawText(TextFormat("Button: \"I am inactive\" \n"), 20, 20, 20, WHITE);
            }
        }
}

