#pragma once

#include <string>

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
