#include <SDL3/SDL.h>
#include <iostream>

#include "maze/maze.hh"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    auto m = maze(125);
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m.size(); j++)
        {
            if (m[i][j])
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
