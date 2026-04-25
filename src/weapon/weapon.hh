#pragma once

#include <string>
#include <vector>

#include "../utils/utils.hh"

class Weapon
{
private:
    std::string name_;
    std::vector<Dice> dices_;
    int add_dmg_; // additional damage
    std::string description_;

public:
    Weapon(std::string name, std::string description, std::vector<Dice> dices);
    Weapon(std::string name, std::string description, std::vector<Dice> dices, int additional_damage);
    std::string get_name() const;
    int damage();
    std::string get_damage_info() const;
    std::string get_description() const;
};