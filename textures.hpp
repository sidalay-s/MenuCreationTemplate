#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <raylib.h>

struct MainMenu {
    Texture2D Start {(LoadTexture("images/StartButton.png"))};
    Texture2D StartHovered {(LoadTexture("images/StartButtonHovered.png"))};
    Texture2D StartActive {(LoadTexture("images/StartButtonActive.png"))};

    Texture2D Settings {LoadTexture("")};

    Texture2D Quit {LoadTexture("")};
};

#endif