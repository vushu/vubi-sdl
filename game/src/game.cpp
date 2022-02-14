#include "game.hpp"
#include <vubi/application.hpp>
#include <string>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

Game::Game(std::string title, int width, int height): vubi::Application(title, width, height) {}

Game::~Game() {
    SDL_DestroyTexture(welcome_texture);
    Mix_FreeMusic(music);
}

void Game::init() {
    init_welcome();
    play_sound();
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
    draw_welcome();

    render();
}


void Game::play_sound() {
    music = Mix_LoadMUS("resources/sounds/just_a_sound.mp3");
    Mix_PlayMusic(music, 0);

}

void Game::draw_welcome() {
    int texture_width = 0;
    int texture_height = 0;
    SDL_QueryTexture(welcome_texture, nullptr, nullptr, &texture_width, &texture_height);
    SDL_Rect draw_texture_rect = { 100, 20, texture_width, texture_height};
    SDL_RenderCopy(renderer_, welcome_texture, nullptr, &draw_texture_rect);
}

void Game::init_welcome() {
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface * surface = TTF_RenderText_Solid(default_font_, "Welcome!", color);
    welcome_texture = SDL_CreateTextureFromSurface(renderer_, surface);
    SDL_FreeSurface(surface);
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
