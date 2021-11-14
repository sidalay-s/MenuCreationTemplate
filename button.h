#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>
#include "window.hpp"

class Button 
{
private:
    Window* WinSize{};
    Vector2 ScreenPosMultiplier{};
    Vector2 ScreenPos{};
    Rectangle Outline{};
    Texture2D Idle{};
    Texture2D Hovered{};
    Texture2D Active{};
    bool isActive{false};
    bool isPressed{false};

public:
    Button(Window& WinDimensions,
           Vector2 ScreenPosMultiplier = {.5f, .5f}, 
           Rectangle Outline = {0.f,0.f,100.f,100.f}, 
           Texture2D Idle = {LoadTexture("images/path")},
           Texture2D Hovered = {LoadTexture("images/path")}, 
           Texture2D Active = {LoadTexture("images/path")});
    ~Button();
    void Tick();
    void Draw();
    bool isHovered();
    bool isActivated() {return isActive;}
};

#endif