#include "Object.h"
#include "Texture.h"

Object::Object(const char* textureSheet, int x, int y) {
    texture = Texture::loadTexture(textureSheet);

    xPos = x;
    yPos = y;
}

Object::~Object() {

}

void Object::update() {
    xPos++;
    yPos++;

    srcRect.w = 360;
    srcRect.h = 360;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = xPos;
    dstRect.y = yPos;
    dstRect.w = srcRect.w * 0.5;
    dstRect.h = srcRect.h * 0.5;
}

void Object::render() {
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}