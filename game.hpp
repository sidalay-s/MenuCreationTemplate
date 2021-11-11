#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include <string>
#include "window.hpp"
#include "button.h"

enum class GameState 
{
    RUNNING, PAUSED, GAMEOVER, MAINMENU
};

namespace Game 
{
    void Run();
    void Initialize(Window Window, int FPS, std::string Title);
    void Tick(Window& Window);
    void Update();
    void Draw();
    void CheckScreenSizing(Window& Window);
    void SetFullScreen(Window& Window);
    bool GameShouldClose();
}

#endif