#pragma once
#include "Components.h"

class PositionComponent : public Component {
    private:
    int xPos;
    int yPos;

    public:

    PositionComponent() {
        xPos = 0;
        yPos = 0;
    }

    PositionComponent(int x, int y) {
        xPos = x;
        yPos = y;
    }

    int getX() {return xPos;}
    int getY() {return yPos;}

    void init() override {
        
    }

    void update() override {
        xPos++;
        yPos++;
    }

    void setPos(int x, int y) {
        xPos = x;
        yPos = y;
    }

};