#pragma once
#include "../Game.h"
#include "Components.h"

class ControllerComponent : public Component
{
    public:
    TransformComponent *transform;

    const Uint8* keystates = SDL_GetKeyboardState(NULL); 

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
        //transform->velocity.x = 0;
        //transform->velocity.y = 0;

        transform->horizontalPressed = false;
        transform->verticalPressed = false;

        if (keystates[SDL_SCANCODE_W]) {
            transform->velocity.y -= 0.1;
            transform->verticalPressed = true;
        }
        if (keystates[SDL_SCANCODE_S]) {
            transform->velocity.y += 0.1;
            transform->verticalPressed = true;
        }
        if (keystates[SDL_SCANCODE_A]) {
            transform->velocity.x -= 0.1;
            transform->horizontalPressed  = true;
        }
        if (keystates[SDL_SCANCODE_D]) {
            transform->velocity.x += 0.1;
            transform->horizontalPressed  = true;
        }
    }
};

