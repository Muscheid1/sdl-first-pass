#include "Map.h"
#include "Texture.h"
#include <fstream>
#include <sstream>

Map::Map() {
    dirt = Texture::loadTexture("assets/dirt.png");
    grass = Texture::loadTexture("assets/grass.png");
    water = Texture::loadTexture("assets/water.png");

    src.x = 0;
    src.y = 0;
    src.h = 16;
    src.w = 16;
    dst.w = 60;
    dst.h = 60;
}

Map::~Map() {
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
}

void Map::loadMap(const char* mapPath) {
    std::fstream mapFile;
    mapFile.open(mapPath);
    std::string line;
    for (int row = 0; row < 18; row++) {
        std::getline(mapFile, line);
        std::stringstream ss(line);
        std::string value;
        for (int col = 0; col < 32; col++) {
            std::getline(ss, value, ',');
            map[row][col] = std::stoi(value);
        }
    }
    mapFile.close();
}

void Map::drawMap() {
    for (int row = 0; row < 18; row++) {
        for (int col = 0; col < 32; col++) {
            dst.y = row * 60;
            dst.x = col * 60;
            switch (map[row][col]) {
                case 0:
                    Texture::draw(dirt, src, dst);
                    break;
                case 1:
                    Texture::draw(grass, src, dst);
                    break;
                case 2:
                    Texture::draw(water, src, dst);
                default:
                    break;
            }
        }
    }
}