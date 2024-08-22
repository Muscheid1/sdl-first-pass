#include "Object.h"
#include "Texture.h"

Object::Object(const char* textureSheet, SDL_Renderer* ren, int x, int y) {
    renderer = ren;
    texture = Texture::loadTexture(textureSheet, renderer);

    xPos = x;
    yPos = y;
}

Object::~Object() {

}

void Object::update() {
    if (right) {
        xPos++;
    }
    else {
        xPos--;
    }
    if (down) {
        yPos++;
    }
    else {
        yPos--;
    }

    if (xPos == 800 - 180) {
        right = false;
    }
    if (xPos == 0) {
        right = true;
    }
    if (yPos == 600 - 180) {
        down = false;
    }
    if (yPos == 0) {
        down = true;
    }

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
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}