#include "Game.h"
#include "Texture.h"
#include "Map.h"
#include "ECS/Components.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& player = manager.addEntity();

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

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    map = new Map();
    map->loadMap("maps/lvl1.csv");

    prevTicks = 0;
    ticks = 0;

    isRunning = true;

    player.addComponent<TransformComponent>(0, 0);
    player.addComponent<SpriteComponent>("assets/ball.png", 16, 16, 64, 64);
    player.addComponent<ControllerComponent>();
}

void Game::handleEvents() {
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

    manager.refresh();
    manager.update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->drawMap();
    manager.draw();
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