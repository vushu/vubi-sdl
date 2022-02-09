#pragma once
#include <SDL2/SDL.h>
#include <string>
namespace vubi {
    class Application {
        public:
            Application (std::string title, int width, int height): title_(title), width_(width), height_(height){}
            ~Application ();
            void run();

        protected:
            std::string title_;
            int width_, height_;

            SDL_Window* window_;
            SDL_Renderer* renderer_;
            SDL_Surface* screen_surface_;
            virtual void input(SDL_Event& event);
            virtual void update();
            virtual void init();
            void draw_color(int r, int g, int b, int a);
            void clear();
            void clear(int r, int g, int b, int a);
            void render();
            void quit();
        private:
            bool running_ = true;
            const Uint32 fps_ = 60;
            const Uint32 minframetime_ = 1000 / fps_;
            void setup_defaults();
            bool setup_sdl();
            void game_loop();
            void destroy_sdl();
    };
}
