#include <random>

class Dice
{
private:
    int max_dice_;
    ;
    std::mt19937 rng_;
    std::uniform_int_distribution<std::mt19937::result_type> dist_;

public:
    Dice(int n);
    int roll();
    int get_max();
};

extern Dice d4;
extern Dice d6;
extern Dice d8;
extern Dice d10;
extern Dice d20;