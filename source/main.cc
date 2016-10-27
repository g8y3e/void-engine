#include <void_engine/base/game.h>
#include <void_engine/base/debug/logger.h>

int main(int argc, char** argv) {
    using namespace void_engine;
    LOGWARN("Game started!");

    Game game("test_game");
    game.init();

    return game.run();
}