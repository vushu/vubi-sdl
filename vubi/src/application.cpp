#include <SDL_render.h>
#include <SDL_ttf.h>
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

    if (success)
    {
        if (TTF_Init() == -1){
            SDL_Log("Failed to init TTF: %s", TTF_GetError());
            success = false;
        }
        else
            this->default_font_ = TTF_OpenFont("resources/fonts/Lato-Regular.ttf", 25);

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
    IMG_Quit();
    TTF_CloseFont(default_font_);
    TTF_Quit();
    SDL_Quit();
}

void Application::handle_inputs(SDL_Event& event) {

    while (SDL_PollEvent (&event) != 0)
    {
        input(event);
    }

}

void Application::game_loop() {
    SDL_Event event;
    Uint64 now;
    Uint64 last;
    float delta_time;

    while (running_)
    {
        now = SDL_GetPerformanceCounter();

        //Game logic
        handle_inputs(event);
        update();

        last = SDL_GetPerformanceCounter();

        //So we aren't hogging the CPU
        delta_time = (last - now) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(std::floor(ms_per_frame - delta_time));

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


