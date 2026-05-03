#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>

#include "scene/scene.hh"

class Scene; // forward declaration

class Game
{
private:
    bool running_ = true;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    MIX_Mixer *mixer_;
    MIX_Audio *audio_;
    MIX_Track *track_;
    Scene *current_scene_ = nullptr;

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
