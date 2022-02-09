#pragma once
#include <vubi/application.hpp>
#include <string>

class Game : public vubi::Application {
    public:
        // constructors, assignment, destructor
        Game(std::string title, int width, int height);
        ~Game();

    private:

};
