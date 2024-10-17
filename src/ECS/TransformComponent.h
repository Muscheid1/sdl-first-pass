#pragma once
#include "Components.h"
#include "../Vector2D.h"
#include <cmath>
#include <algorithm>

class TransformComponent : public Component {
    public:

    Vector2D position;
    Vector2D velocity;

    int height = 16;
    int width = 16;
    int scale = 4;

    float speed = 2.0;
    float friction = 0.005;
    float bounce = 0.9;
    float gravity = 0.18;
    float mousePull = 100.0;
    

    TransformComponent() {
        position.x = 0;
        position.y = 0;
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void update() override {

        //Move player
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

        //Window boundary hits
        if (position.x <= 0.0) {
            velocity.x *= -bounce;
            position.x = 0.0;
        }
        else if (position.x >= 1856.0) {
            velocity.x *= -bounce;
            position.x = 1856.0;
        }
        if (position.y <= 0.0) {
            velocity.y *= -bounce;
            position.y = 0.0;
        }
        else if (position.y >= 1016.0) {
            velocity.y *= -bounce;
            position.y = 1016.0;
        }

        //Friction
        if (position.y > 1015.0) {
            velocity.x -= velocity.x * friction * 4.0;
        }
        else {
            velocity.x -= velocity.x * friction;
        }
        velocity.y -= velocity.y * friction;

        //Gravity
        velocity.y += gravity;


        /*
        //Mouse
        int mouseX;
        int mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (mouseX > position.x) {
            velocity.x += std::min(0.3, mousePull / pow(mouseX - position.x, 2.0));
        }
        else if (mouseX < position.x){ 
            velocity.x -= std::min(0.3, mousePull / pow(mouseX - position.x, 2.0));
        }
        if (mouseY > position.y) {
            velocity.y += std::min(0.3, mousePull / pow(mouseY - position.y, 2.0));
        }
        else if (mouseY < position.y) {
            velocity.y -= std::min(0.3, mousePull / pow(mouseY - position.y, 2.0));
        }

        std::cout << mouseX << "," << mouseY << std::endl;
        */
    }
};