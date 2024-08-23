#include "Game.h"
#include "Texture.h"
#include "Object.h"
#include "Map.h"

Object* mario;
Object* luigi;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {
    
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    isRunning = false;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL Initialization Failed" << std::endl;
        return;
    }

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!window) {
        std::cout << "Window Creation Failed" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "Renderer Creation Failed" << std::endl;
        return;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    mario = new Object("assets/mario.png", 0, 0);
    luigi = new Object("assets/luigi.png", 300, 300);

    map = new Map();
    map->loadMap(map->lvl1);

    prevTicks = 0;
    ticks = 0;

    isRunning = true;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    //Framerate
    frames++;
    count++;
    int currTicks = SDL_GetTicks();
    ticks = currTicks - prevTicks;
    if (ticks > 1000) {
        std::cout << frames << std::endl;
        frames = 0;
        prevTicks = currTicks;
    }

    mario->update();
    luigi->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->drawMap();
    mario->render();
    luigi->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() { 
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

bool Game::running() {
    return isRunning;
}