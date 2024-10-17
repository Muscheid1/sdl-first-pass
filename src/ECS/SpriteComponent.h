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
        SpriteComponent(const char* path) {
            setTexture(path);
        }

        ~SpriteComponent() {
            SDL_DestroyTexture(texture);
        }

        void setTexture(const char* path) {
            //Maybe check to destroy replaced texture
            texture = Texture::loadTexture(path);
        }

        void init() override {
            transform = &entity->getComponent<TransformComponent>();
            srcRect.w = transform->width;
            srcRect.h = transform->height;
            destRect.w = transform->width * transform->scale;
            destRect.h = transform->height * transform->scale;
        }

        void update() override {
            destRect.x = (int)transform->position.x;
            destRect.y = (int)transform->position.y;
        }

        void draw() override {
            Texture::draw(texture, srcRect, destRect);
        }

};