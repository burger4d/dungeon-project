#include <SDL3/SDL.h>
#include <iostream>

#include "maze/maze.hh"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window;
    window = SDL_CreateWindow("dungeon", 320, 240, SDL_WINDOW_FULLSCREEN);

    SDL_Delay(5000);
    SDL_Quit();
    return 0;
}
