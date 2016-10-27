#include "render.h"

#include <string>

#include <void_engine/base/exception/void_runtime_exception.h>
#include <void_engine/base/debug/logger.h>

namespace void_engine {
    Render::Render() {
    }
    
    Render::~Render() {
    }

    void Render::init(const std::string& name) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::string message = "Can't init SDL video!";
            LOGERROR(message);
            throw VoidRuntimeException(message);
        }

        int width = 640;
        int height = 480;

    #ifdef MOBILE_OS
        window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            0, 0, SDL_WINDOW_OPENGL);
    #else
        SDL_Window* window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    #endif

        if (window_ == nullptr) {
            std::string message = "Can't create SDL window!";
            LOGERROR(message);
            throw VoidRuntimeException(message);
        }

        SDL_Renderer* renderer;

        // We must call SDL_CreateRenderer in order for draw calls to affect this window.
        renderer = SDL_CreateRenderer(window_, -1, 0);

        // Select the color for drawing. It is set to red here.
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);

        // Up until now everything was drawn behind the scenes.
        // This will show the new, red contents of the window.
        SDL_RenderPresent(renderer);

        // Give us time to see the window.
        SDL_Delay(50000);

    }


}