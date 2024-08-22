#pragma once
#include "Game.h"

class Object {
    public:
    Object(const char* textureSheet, SDL_Renderer* ren, int x, int y);
    ~Object();

    void update();
    void render();
    
    private:
    int xPos;
    int yPos;

    bool right = true;
    bool down = true;
    
    SDL_Texture* texture;
    SDL_Rect srcRect, dstRect;
    SDL_Renderer* renderer;
};