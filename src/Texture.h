#pragma once

#include "Game.h"

class Texture {
    public:
    static SDL_Texture* loadTexture(const char* texture);
    static void draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst);
};