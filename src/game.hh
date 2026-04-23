#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

class Game
{
private:
    bool running_ = true;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    SDL_Texture *texture_;
    MIX_Mixer *mixer_;
    MIX_Audio *audio_;
    MIX_Track *track_;

public:
    Game();

    ~Game();

    void run();

    SDL_Window *window() const
    {
        return window_;
    }

    SDL_Renderer *renderer() const
    {
        return renderer_;
    }
};