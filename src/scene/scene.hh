#pragma once
#include <SDL3/SDL.h>

#include <map>
#include <string>

#include "../game.hh"

class Game; // forward declaration

class Scene
{
    private:
        std::map<std::string, SDL_Texture*> textures_;

    public:
        void load_texture(Game &game, std::string name, std::string path);
        void render(Game &game);
        void exit();
};
