#include <iostream>

#include "void_engine/base/game.h"

int main() {
    std::cout << "Game started!" << std::endl;

    void_engine::Game game("test_game");
    game.init();

    return game.run();
}