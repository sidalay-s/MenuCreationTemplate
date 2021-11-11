#include "button.h"

Button::Button(Window& WinDimensions,
               Vector2 ScreenPos, 
               Rectangle Outline, 
               Texture2D Idle, 
               Texture2D Active)
    : WinSize{&WinDimensions}, 
      ScreenPos{WinDimensions.x * ScreenPos.x, WinDimensions.y * ScreenPos.y}, 
      ScreenMultiplier{ScreenPos},
      Outline{Outline}, 
      Idle{Idle}, 
      Active{Active}
{

}

Button::~Button()
{
    UnloadTexture(Idle);
    UnloadTexture(Active);
}

void Button::Tick()
{
    if (IsKeyDown(KEY_A)) {isActive = true;}
    else {isActive = false;}

    if (IsWindowResized())
    {
        ScreenPos.x = WinSize->x * ScreenMultiplier.x;
        ScreenPos.y = WinSize->y * ScreenMultiplier.y;
    }
}

void Button::Draw()
{
    if (isActive)
    {
        DrawRectangle(ScreenPos.x, ScreenPos.y, Outline.width, Outline.height, DARKBLUE);
    }
    else 
    {
        DrawRectangle(ScreenPos.x, ScreenPos.y, Outline.width, Outline.height, RED);
    }
}
