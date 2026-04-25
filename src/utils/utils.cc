#include "utils.hh"

Dice::Dice(int n)
    : rng_(dev_())
    , dist_(1, n)
    , max_dice_(n)
{}

int Dice::roll()
{
    return dist_(rng_);
}

Dice d4 = Dice(4);
Dice d6 = Dice(6);
Dice d8 = Dice(8);
Dice d10 = Dice(10);
Dice d20 = Dice(20);
