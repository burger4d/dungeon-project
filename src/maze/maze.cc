#include "maze.hh"

std::vector<std::vector<int>> maze(size_t size)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist4(1, 4);

    std::vector<int> row(size, 1);
    std::vector<std::vector<int>> result(size, row); // is the result AND is
                                                     // the matrix used for
                                                     // checking if a node has
                                                     // been visited or not

    std::stack<std::array<int, 2>> s;
    std::array<int, 2> starting = { 1, 1 };
    s.push(starting);

    while (!s.empty())
        {
            std::array<int, 2> node = s.top();
            int i = node[0];
            int j = node[1];
            result[i][j] = 0;

            std::vector<std::array<int, 2>> neighbours;
            if (i > 1 && result[i - 2][j])
            {
                neighbours.push_back({ i - 2, j });
            }
            if (j > 1 && result[i][j - 2])
            {
                neighbours.push_back({ i, j - 2 });
            }
            if (i < size - 2 && result[i + 2][j])
            {
                neighbours.push_back({ i + 2, j });
            }
            if (j < size - 2 && result[i][j + 2])
            {
                neighbours.push_back({ i, j + 2 });
            }

            if (neighbours.size() > 0)
            {
                auto choice = neighbours[dist4(rng) % neighbours.size()];
                s.push(choice);
                result[choice[0]][choice[1]] = 0;
                
                // remove the wall between
                result[(choice[0] + i) / 2][(choice[1] + j) / 2] = 0;
            }
            else
            {
                s.pop();
            }
        }

    return result;
}
