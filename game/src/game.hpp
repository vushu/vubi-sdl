#pragma once
#include <SDL_mixer.h>
#include <vubi/application.hpp>
#include <string>

class Game : public vubi::Application {
    public:
        // constructors, assignment, destructor
        Game(std::string title, int width, int height);
        ~Game();

        void input(SDL_Event& event) override;
        void update() override;
        void init() override;
        void draw_rectangle();
        void init_welcome();
        void draw_welcome();
        void play_sound();

    private:
        SDL_Texture* welcome_texture;
        Mix_Chunk* sound_fx;
        Mix_Music* music;

};
