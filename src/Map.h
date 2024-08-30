#pragma once
#include "Game.h"

class Map {
    public:
    Map();
    ~Map();

    void loadMap(const char* mapPath);
    void drawMap();

    private:

    SDL_Rect src, dst;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[18][32];
};