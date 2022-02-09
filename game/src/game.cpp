#include "game.hpp"
#include "vubi/application.hpp"
#include <SDL_render.h>
#include <SDL_timer.h>
#include <string>
#include <iostream>

Game::Game(std::string title, int width, int height): vubi::Application(title, width, height) {}

Game::~Game() {
}

void Game::init() {

}

void Game::input(SDL_Event& event) {
    switch (event.type)
    {
        case SDL_QUIT:
            quit();
            break;

        case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE)
                              quit();
                          break;

    }


}

void Game::update() {

    clear();
    // Draw stuff
    draw_rectangle();
    render();
}

void Game::draw_rectangle() {
    SDL_Rect rectangle;
    rectangle.x = 20;
    rectangle.y = 20;
    rectangle.w = 50;
    rectangle.h = 50;

    SDL_SetRenderDrawColor(renderer_, 0, 0, 255, 255 );

    SDL_RenderFillRect(renderer_, &rectangle);
}
