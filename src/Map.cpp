#include "Map.h"
#include "Texture.h"

Map::Map() {
    dirt = Texture::loadTexture("assets/dirt.png");
    grass = Texture::loadTexture("assets/grass.png");
    water = Texture::loadTexture("assets/water.png");
    
}

Map::~Map() {
    
}

void Map::loadMap() {

}

void Map::drawMap() {

}