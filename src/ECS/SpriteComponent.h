#pragma once
#include "Components.h"
#include "../Game.h"

class SpriteComponent : public Component
{
    private:
        TransformComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

    public:

        SpriteComponent() = default;
        SpriteComponent(const char* path, int srcWidth, int srcHeight, int destWidth, int destHeight) {
            setTexture(path, srcWidth, srcHeight, destWidth, destHeight);
        }

        ~SpriteComponent() {
            SDL_DestroyTexture(texture);
        }

        void setTexture(const char* path, int srcWidth, int srcHeight, int destWidth, int destHeight) {
            texture = Texture::loadTexture(path);
            srcRect.w = srcWidth;
            srcRect.h = srcHeight;
            destRect.w = destWidth;
            destRect.h = destHeight;
        }

        void init() override {
            transform = &entity->getComponent<TransformComponent>();
        }

        void update() override {
            destRect.x = (int)transform->position.x;
            destRect.y = (int)transform->position.y;
        }

        void draw() override {
            Texture::draw(texture, srcRect, destRect);
        }

};