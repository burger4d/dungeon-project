#include "maze.hh"

std::vector<std::vector<int>> maze(size_t size)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(0, 3);

    std::vector<int> row(size, dist4(rng));
    std::vector<std::vector<int>> m(size, row);
    
    // TODO
    
    return m;
}
