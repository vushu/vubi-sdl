#pragma once
#include <SDL2/SDL.h>
namespace vubi {
    class Application {
        public:
            Application ();
            ~Application ();
            void run();

        private:
            SDL_Window* sdl_window;
    };
}
