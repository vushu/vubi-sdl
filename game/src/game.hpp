#pragma once
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

    private:

};
