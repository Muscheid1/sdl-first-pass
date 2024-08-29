#pragma once
#include "Components.h"
#include "../Vector2D.h"
#include <cmath>

class TransformComponent : public Component {
    public:

    Vector2D position;
    Vector2D velocity;

    int speed = 1;
    float friction = 0.02;
    float stopTolerance = 0.03;
    float gravity = 0.06;
    bool horizontalPressed;
    bool verticalPressed;
    

    TransformComponent() {
        position.x = 0;
        position.y = 0;
        horizontalPressed = false;
        verticalPressed = false;
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
            velocity.x *= -1.0;
            position.x = 0.0;
        }
        else if (position.x >= 710.0) {
            velocity.x *= -1.0;
            position.x = 710.0;
        }
        if (position.y <= 0.0) {
            velocity.y *= -1.0;
            position.y = 0.0;
        }
        else if (position.y >= 550.0) {
            velocity.y *= -1.0;
            position.y = 550.0;
        }

        //Friction
        if (velocity.x < 0.0) {
            velocity.x += friction;
        }
        else if (velocity.x > 0.0) {
            velocity.x -= friction;
        }

        if (velocity.y < 0.0) {
            velocity.y += friction;
        }
        else if (velocity.y > 0.0) {
            velocity.y -= friction;
        }

        //Gravity
        velocity.y += gravity;


        //Full stop
        if (!horizontalPressed && abs(velocity.x) < stopTolerance) {
            velocity.x = 0.0;
        }
        if (!verticalPressed && velocity.y > 0.0 && position.y > 549.0 && velocity.y < gravity * 1.1) {
            velocity.y = 0.0;
        }

        std::cout << velocity << std::endl;
    }


};