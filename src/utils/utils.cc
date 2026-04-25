#include "utils.hh"

Dice::Dice(int n)
    : rng_(std::random_device{}())
    , dist_(1, n)
    , max_dice_(n)
{}

int Dice::roll()
{
    return dist_(rng_);
}

int Dice::get_max()
{
    return max_dice_;
}

Dice d4 = Dice(4);
Dice d6 = Dice(6);
Dice d8 = Dice(8);
Dice d10 = Dice(10);
Dice d20 = Dice(20);
