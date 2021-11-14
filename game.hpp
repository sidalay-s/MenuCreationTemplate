#ifndef GAME_HPP
#define GAME_HPP

#include <raylib.h>
#include <string>
#include <array>
#include "window.hpp"
#include "button.h"

enum class GameState 
{
    MAINMENU, RUNNING, PAUSED, GAMEOVER
};

namespace Game 
{
    void Run();
    void Initialize(Window& Window, int FPS, std::string Title);
    void Tick(Window& Window, std::array<std::array<Button*, 1>, 1>& Buttons);
    void CheckScreenSizing(Window& Window);
    void SetFullScreen(Window& Window);
    template <typename T>
    void Update(std::array<std::array<T*, 1>, 1>& Container);
    void Draw(std::array<std::array<Button*, 1>, 1>& Buttons);
}

#endif