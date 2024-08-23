#include "Map.h"
#include "Texture.h"

Map::Map() {
    dirt = Texture::loadTexture("assets/dirt.png");
    grass = Texture::loadTexture("assets/grass.png");
    water = Texture::loadTexture("assets/water.png");

    src.x = 0;
    src.y = 0;
    src.h = 16;
    src.w = 16;
    dst.w = 16;
    dst.h = 16;
}

Map::~Map() {
    
}

void Map::loadMap(int arr[20][25]) {
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 25; col++) {
            map[row][col] = arr[row][col];
        }
    }
}

void Map::drawMap() {
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 25; col++) {
            dst.y = row * 16;
            dst.x = col * 16;
            switch (map[row][col]) {
                case 0:
                    SDL_RenderCopy(Game::renderer, dirt, &src, &dst);
                    break;
                case 1:
                    SDL_RenderCopy(Game::renderer, grass, &src, &dst);
                    break;
                case 2:
                    SDL_RenderCopy(Game::renderer, water, &src, &dst);
                default:
                    break;
            }
        }
    }
}