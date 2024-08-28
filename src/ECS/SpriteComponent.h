#pragma once
#include "Components.h"
#include "../Game.h"

class SpriteComponent : public Component
{
    private:
        PositionComponent *position;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

    public:

        SpriteComponent() = default;
        SpriteComponent(const char* path, int srcWidth, int srcHeight, int destWidth, int destHeight) {
            setTexture(path, srcWidth, srcHeight, destWidth, destHeight);
        }

        void setTexture(const char* path, int srcWidth, int srcHeight, int destWidth, int destHeight) {
            texture = Texture::loadTexture(path);
            srcRect.w = srcWidth;
            srcRect.h = srcHeight;
            destRect.w = destWidth;
            destRect.h = destHeight;
        }

        void init() override {
            position = &entity->getComponent<PositionComponent>();
        }

        void update() override {
            destRect.x = position->getX();
            destRect.y = position->getY();
        }

        void draw() override {
            Texture::draw(texture, srcRect, destRect);
        }

};