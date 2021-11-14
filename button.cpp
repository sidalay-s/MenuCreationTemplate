#include "button.h"

// Constructor
Button::Button(Window& WinDimensions,
               Vector2 ScreenPosMultiplier,
               Rectangle Outline, 
               Texture2D Idle,
               Texture2D Hovered, 
               Texture2D Active)
    : WinSize{&WinDimensions}, 
      ScreenPosMultiplier{ScreenPosMultiplier},
      ScreenPos{(WinDimensions.x * ScreenPosMultiplier.x) - (Outline.width/2), (WinDimensions.y * ScreenPosMultiplier.y) - (Outline.height/2)}, 
      Outline{Outline}, 
      Idle{Idle},
      Hovered{Hovered}, 
      Active{Active}
{

}

// Destructor
Button::~Button()
{
    UnloadTexture(Idle);
    UnloadTexture(Hovered);
    UnloadTexture(Active);
}


void Button::Tick()
{
    // First check if mouse-cursor is hovering before checking for left-click
    if (isHovered()) 
    {
        // Left-click sets button state to Active [true, false]
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {isPressed = true; isActive = !isActive;}
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {isPressed = false;}
    }
    else 
    {
        // When lifting left-click
        isPressed = false;
    }

    // Check if window is resized and adjust ScreenPos accordingly    
    if (IsWindowResized())
    {
        ScreenPos.x = (WinSize->x * ScreenPosMultiplier.x) - (Outline.width/2);
        ScreenPos.y = (WinSize->y * ScreenPosMultiplier.y) - (Outline.height/2);
    }
}

void Button::Draw()
{
    // Change button color/texture based on state.
    if (isPressed)
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

// Check if cursor is within the bounds of the button dimensions defined by ScreenPos, Outline.width, & Outline.height
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
