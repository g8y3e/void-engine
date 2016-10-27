#pragma once

#include <string>

#include <void_engine/third_party/SDL2/SDL.h>

namespace void_engine {
    class Game {
    public:
        Game(const std::string& name);
        ~Game();

    public:
        void init();

        int run();

    private:
        std::string name_;
    };
}
