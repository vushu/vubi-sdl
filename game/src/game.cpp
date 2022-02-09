#include "game.hpp"
#include "vubi/application.hpp"
#include <string>

Game::Game(std::string title, int width, int height): vubi::Application(title, width, height) {}

Game::~Game() {
}

