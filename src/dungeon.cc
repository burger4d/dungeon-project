#include <SDL3/SDL.h>
#include <iostream>

#include "maze/maze.hh"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    auto m = maze(5);
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m.size(); j++)
        {
            std::cout << m[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
