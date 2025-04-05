#pragma once
#include <string>
#include <ostream>

class Armor {
    std::string name;
    int defense;
public:
    Armor(const std::string& name, int defense) : name(name), defense(defense) {}
    int getDefense() const { return defense; }
    friend std::ostream& operator<<(std::ostream& os, const Armor& armor) {
        os << armor.name << " (Defense: " << armor.defense << ")";
        return os;
    }
};