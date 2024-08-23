#pragma once
#include "Game.h"

class Object {
    public:
    Object(const char* textureSheet, int x, int y);
    ~Object();

    void update();
    void render();
    
    private:
    int xPos;
    int yPos;
    
    SDL_Texture* texture;
    SDL_Rect srcRect, dstRect;
};