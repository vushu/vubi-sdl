#pragma once
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <string>
namespace vubi {
    class Application {
        public:
            Application (std::string title, int width, int height): title_(title), width_(width), height_(height){
            }
            ~Application ();
            void run();

            Application(Application const&) = delete;
            void operator=(Application const&) = delete;

        protected:
            std::string title_;
            int width_, height_;

            SDL_Window* window_;
            SDL_Renderer* renderer_;
            SDL_Surface* screen_surface_;
            TTF_Font* default_font_;

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
            const float ms_per_frame = 1000.0f/60.0;
            void setup_defaults();
            void handle_inputs(SDL_Event& event);
            bool setup_sdl();
            void game_loop();
            void destroy_sdl();
    };

    static Application* app;
}
