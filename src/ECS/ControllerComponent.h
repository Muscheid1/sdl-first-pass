#pragma once
#include "../Game.h"
#include "Components.h"

class ControllerComponent : public Component
{
    public:
    TransformComponent *transform;

    const Uint8* keystates = SDL_GetKeyboardState(NULL); 

    float acceleration = 0.3;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
        //transform->velocity.x = 0;
        //transform->velocity.y = 0;

        if (keystates[SDL_SCANCODE_W]) {
            if (keystates[SDL_SCANCODE_A] || keystates[SDL_SCANCODE_D]) {
                transform->velocity.y -= acceleration * sqrt(2) / 2.0; //Make this constant
            }
            else {
                transform->velocity.y -= acceleration;
            }
        }
        if (keystates[SDL_SCANCODE_S]) {
            if (keystates[SDL_SCANCODE_A] || keystates[SDL_SCANCODE_D]) {
                transform->velocity.y += acceleration * sqrt(2) / 2.0;
            }
            else {
                transform->velocity.y += acceleration;
            }
        }
        if (keystates[SDL_SCANCODE_A]) {
            if (keystates[SDL_SCANCODE_W] || keystates[SDL_SCANCODE_S]) {
                transform->velocity.x -= acceleration * sqrt(2) / 2.0;
            }
            else {
                transform->velocity.x -= acceleration;
            }
        }
        if (keystates[SDL_SCANCODE_D]) {
            if (keystates[SDL_SCANCODE_W] || keystates[SDL_SCANCODE_S]) {
                transform->velocity.x += acceleration * sqrt(2) / 2.0;
            }
            else {
                transform->velocity.x += acceleration;
            }
        }
    }
};

