#include "game.h"

#include <void_engine/base/debug/logger.h>
#include <void_engine/base/render/render.h>

void log(const std::string& message) {
    std::cout << message << std::endl;
}

namespace void_engine {
    Game::Game(const std::string& name) 
        : name_(name) {
    }

    Game::~Game() {
    }

    void Game::init() {
        std::string message = "Game \"";
        message.append(this->name_).append("\" init!");
        LOGINFO(message);

        Render render;
        render.init(this->name_);
    }

    int Game::run() {
        std::string message = "Game \"";
        message.append(this->name_).append("\" running!");
        LOGINFO(message);

        std::cin.get();

        return 0;
    }
}