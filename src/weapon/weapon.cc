#include "weapon.hh"

Weapon::Weapon(std::string name, std::string description, std::vector<Dice> dices)
{
    Weapon(name, description, dices, 0);
}

Weapon::Weapon(std::string name, std::string description, std::vector<Dice> dices, int additional_damage)
    : name_(name)
    , description_(description)
    , dices_(dices)
    , add_dmg_(additional_damage)
{}

std::string Weapon::get_name() const
{
    return name_;
}

int Weapon::damage()
{
    int score = add_dmg_;
    for (auto &dice : dices_)
    {
        score += dice.roll();
    }
    return score;
}

std::string Weapon::get_damage_info() const
{
    std::string result = "";

    for (size_t i = 0; i < dices_.size(); i++)
    {
        Dice dice = dices_.at(i);
        if (i != 0)
            result += " + ";

        result += "D";
        result += std::to_string(dice.get_max());
    }

    if (dices_.size() != 0)
        result += " + ";

    result += std::to_string(add_dmg_);

    return result;
}

std::string Weapon::get_description() const
{
    return description_;
}