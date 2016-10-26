#include "game.h"

// temp
#include <iostream>

namespace void_engine {
    Game::Game(const std::string& name) 
        : name_(name) {
    }

    Game::~Game() {

    }

    void Game::init() {
        std::cout << "Game \"" << this->name_ << "\" init!" << std::endl;
    }

    int Game::run() {
        std::cout << "Game \"" << this->name_ << "\" running!"<< std::endl;
        std::cin.get();

        return 0;
    }
}