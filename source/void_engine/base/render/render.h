#pragma once

#include <string>

#include <void_engine/third_party/SDL2/SDL.h>

namespace void_engine {
    class Render {
    public:
        Render();
        ~Render();

    public:
        void init(const std::string& name);

    private:
        SDL_Window* window_;
    };
}