#include <vubi/application.hpp>
#include <SDL2/SDL_image.h>
using namespace vubi;

Application::~Application() {

}

bool Application::setup_sdl()  {
    bool success = false;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }

    if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &window_, &renderer_)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }
    else{
        success = true;
    }

    if (success){

        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            success = false;
        }
        else
        {
            success = true;
        }
    }
    return success;
}

bool Application::run() {
    return setup_sdl();
}


