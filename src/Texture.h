#pragma once

#include "Game.h"

class Texture {
    public:
    static SDL_Texture* loadTexture(const char* texture, SDL_Renderer* ren);
};