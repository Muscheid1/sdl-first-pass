#pragma once
#include "Components.h"
#include "../Vector2D.h"
#include <cmath>

class TransformComponent : public Component {
    public:

    Vector2D position;
    Vector2D velocity;

    float speed = 2.0;
    float friction = 0.005;
    float bounce = 0.9;
    float gravity = 0.18;
    

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
    }
};