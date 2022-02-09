#include "game.hpp"
#include "vubi/application.hpp"
#include <SDL_timer.h>
#include <string>

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
    render();
}
