#include <gtest/gtest.h>

#include "utils.hh"

TEST(test_dice, correct_dice_number)
{
    Dice d7 = Dice(7);
    EXPECT_EQ(7, d7.get_max());
}

TEST(test_dice, lot_of_rolls)
{
    for (int i = 2; i <= 100; i++)
    {
        Dice di = Dice(i);
        for (int j = 0; j < 100; j++)
        {
            int roll_j = di.roll();
            EXPECT_EQ(roll_j, roll_j % (i + 1));
        }
    }
}