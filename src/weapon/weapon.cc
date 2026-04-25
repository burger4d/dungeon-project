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

Weapon knife = Weapon("couteau", "Un simple couteau. Coupe plutôt bien. Interdit de porter tout type d'armes blanches depuis le début de la période révolutionnaire.", {d4});
Weapon club = Weapon("gourdin", "Une arme primitive et universelle. Gros bâton en bois.", {d6});
Weapon swordcane = Weapon("canne-épée", "Une lame dissimulée dans une canne creuse. Le port d'arme blanche étant interdit depuis le début de la Révolution, elle peut s'avérer fort pratique...", {d6});
Weapon pistol = Weapon("pistolet d'arçon", "Pistolet utilsé par la cavalerie, comme le nom l'indique. Utilisé au combat rapproché.", {d10});
Weapon rifle = Weapon("fusil modèle 1777", "Arme conçue par l'ingénieur Gribeauval sous l'Ancien régime, employé massivement dans l'armée.", {d6, d6}, 4);
Weapon bayonnet = Weapon("fusil à baïonnette", "Arme polyvalente, une arme à feu dotée d'une lame au bout de son canon, pouvant servir de lance improvisée.", {d10, d6}, 2);
Weapon saber = Weapon("sabre français", "Arme de l'ancien régime. Interdit de porter tout type d'armes blanches depuis le début de la période révolutionnaire.", {d8}, 1);
Weapon axe = Weapon("hache", "Une simple hache pour couper du bois.", {d8}, 2);
Weapon hatchet = Weapon("hachette", "Petite hache pour fendre du bois.", {d6}, 1);