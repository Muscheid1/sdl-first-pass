#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/include/SDL2/SDL_image.h>
//#include <SDL2/SDL_image.h>

class Game {
    public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    static SDL_Renderer *renderer;
    static SDL_Event event;

    private:
    int prevTicks;
    int ticks;
    int frames;
    int count = 0;
    bool isRunning;
    SDL_Window *window;
};
