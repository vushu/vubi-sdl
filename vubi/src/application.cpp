#include <vubi/application.hpp>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace vubi;

Application::~Application() {

}

bool Application::setup_sdl()  {
    bool success = true;


    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Failed to initialise SDL\n";
        return false;
    }

    // Create a window
    window_ = SDL_CreateWindow(title_.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width_,
            height_,
            SDL_WINDOW_OPENGL);
    if (window_ == nullptr)
    {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return false;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        return false;
    }

    if (success){

        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            return false;
        }
        screen_surface_ = SDL_GetWindowSurface(window_);
    }

    return success;
}

bool Application::run() {
    return setup_sdl();
}


