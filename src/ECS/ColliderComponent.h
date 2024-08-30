#pragma once
#include "../Game.h"
#include "Components.h"

class ColliderComponent : public Component {
    public:
    int x;

    private:
    SDL_Rect collider;
    std::string tag;

    TransformComponent* transform;

    void init() override {
        if (!entity->hasComponent<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }
};