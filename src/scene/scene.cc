#include "scene.hh"

void Scene::load_texture(Game &game, std::string name, std::string path)
{
    SDL_Texture *tex = IMG_LoadTexture(game.renderer(), path.c_str());
    textures_[name] = tex;
}

void Scene::render(Game &game)
{
    SDL_RenderTexture(game.renderer(), textures_["bg"], nullptr, nullptr);
}

void Scene::exit()
{
    for (auto &[key, tex] : textures_)
    {
        SDL_DestroyTexture(tex);
    }
    textures_.clear();
}
