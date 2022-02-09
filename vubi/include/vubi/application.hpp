#pragma once
#include <SDL2/SDL.h>
#include <string>
namespace vubi {
    class Application {
        public:
            Application (std::string title, int width, int height): title_(title), width_(width), height_(height){}
            ~Application ();
            bool run();

        protected:
            std::string title_;
            int width_, height_;

            SDL_Window* window_;
            SDL_Renderer* renderer_;
            SDL_Surface* screen_surface_;
        private:
            bool setup_sdl();

    };
}
