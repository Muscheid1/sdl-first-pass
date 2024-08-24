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
    if (xPos >= 800 - 384 / 2) {
        right = false;
    }
    else if (xPos <= 0) {
        right = true;
    }
    if (yPos >= 640 - 384 / 2) {
        down = false;
    }
    else if (yPos <= 0) {
        down = true;
    }

    if (right) {
        xPos += 2;
    }
    else {
        xPos -= 2;
    }
    if (down) {
        yPos += 2;
    }
    else {
        yPos -= 2;
    }

    srcRect.w = 384;
    srcRect.h = 384;
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