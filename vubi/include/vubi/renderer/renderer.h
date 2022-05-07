#pragma once
#include <SDL2/SDL.h>
namespace vubi {
    class Renderer {
        virtual void begin_batch() = 0;
        virtual void end_batch() = 0;
        virtual void flush() = 0;
        virtual void draw_color(SDL_Rect& color) = 0;
        virtual void draw_quad(SDL_Rect& rect, float angle) = 0;
    };
}
