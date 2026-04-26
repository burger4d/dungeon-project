#include <gtest/gtest.h>

#include "weapon.hh"

TEST(test_weapon, good_data)
{
    Weapon w1 = Weapon("nom", "description", { d4, d6 }, 2);
    EXPECT_EQ("nom", w1.get_name());
    EXPECT_EQ("description", w1.get_description());
}

TEST(test_weapon, damage_info)
{
    Weapon w1 = Weapon("nom", "description", { d4, d6 }, 2);
    EXPECT_EQ("D4 + D6 + 2", w1.get_damage_info());
}

TEST(test_weapon, damage_info_no_additional_implicit)
{
    Weapon w1 = Weapon("nom", "description", { d4, d6 });
    EXPECT_EQ("D4 + D6", w1.get_damage_info());
}

TEST(test_weapon, damage_info_no_additional_explicit)
{
    Weapon w1 = Weapon("nom", "description", { d4, d6 }, 0);
    EXPECT_EQ("D4 + D6", w1.get_damage_info());
}