#include <SDL_render.h>
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
        std::cout << "Error initializing SDL: " << SDL_GetError () << std::endl;
        return false;
    }

    atexit (&SDL_Quit);
    // Create a window
    window_ = SDL_CreateWindow(title_.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width_,
            height_,
            0);
    if (window_ == nullptr)
    {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr)
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
        else{
            screen_surface_ = SDL_GetWindowSurface(window_);
        }
    }

    return success;
}

//Virtual methods
void Application::init() {}
void Application::input(SDL_Event& event) {}
void Application::update() {}

void Application::destroy_sdl() {
    SDL_FreeSurface(screen_surface_);
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Application::game_loop() {
    SDL_Event event;
    Uint32 frametime;

    while (running_)
    {
        frametime = SDL_GetTicks ();

        while (SDL_PollEvent (&event) != 0)
        {
            input(event);
        }

        update();


        if (SDL_GetTicks () - frametime < minframetime_)
            SDL_Delay (minframetime_ - (SDL_GetTicks () - frametime));

    }
}

void Application::draw_color(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}

void Application::setup_defaults() {
}

void Application::clear(int r, int g, int b, int a) {
    draw_color(r, g, b, a);
    SDL_RenderClear(renderer_);
}

void Application::clear() {
    draw_color(133, 158, 204, 255);
    SDL_RenderClear(renderer_);
}

void Application::render() {
    SDL_RenderPresent(renderer_);
}

void Application::quit() {
    running_ = false;
}

void Application::run() {
    if (setup_sdl()) {
        setup_defaults();
        init();
        game_loop();
        destroy_sdl();
    }
    else{
        std::cout << "Failed to Init SDL" << std::endl;
    }
}


