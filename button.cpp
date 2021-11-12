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
    if (isHovered()) 
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {isActive = true;}
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {isActive = false;}
    }
    else 
    {
        isActive = false;
    }
        
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
        DrawRectangle(ScreenPos.x, ScreenPos.y, Outline.width, Outline.height, WHITE);
    }
    else if (isHovered())
    {
        DrawRectangle(ScreenPos.x, ScreenPos.y, Outline.width, Outline.height, DARKGRAY);
    }
    else 
    {
        DrawRectangle(ScreenPos.x, ScreenPos.y, Outline.width, Outline.height, BLUE);
    }
}

bool Button::isHovered()
{
    if ((GetMousePosition().x >= ScreenPos.x) && 
        (GetMousePosition().x <= ScreenPos.x + Outline.width) &&
        (GetMousePosition().y >= ScreenPos.y) &&
        (GetMousePosition().y <= ScreenPos.y + Outline.height))
    {
        return true;
    }
    else
    {
        return false;
    }
}
