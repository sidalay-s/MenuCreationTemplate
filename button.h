#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>
#include "window.hpp"

class Button 
{
private:
    const Window* WinSize{};
    Vector2 ScreenPos{};
    Vector2 ScreenMultiplier{};
    Rectangle Outline{};
    Texture2D Idle{};
    Texture2D Active{};
    bool isActive{false};

public:
    Button(Window& WinDimensions,
           Vector2 ScreenPos = {.5f, .5f}, 
           Rectangle Outline = {0.f,0.f,100.f,100.f}, 
           Texture2D Idle = {LoadTexture("images/path")}, 
           Texture2D Active = {LoadTexture("images/path")});
    ~Button();
    void Tick();
    bool isActivated() {return isActive;}
    void Draw();
    void LoadIdleTexture(Texture2D Idle) {this->Idle = Idle;}
    void LoadActiveTexture(Texture2D Active) {this->Active = Active;}
    void SetScreenPos(int x, int y);
};

#endif